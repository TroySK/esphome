# DFRobot SEN0623 C1001 mmWave Sensor Implementation Plan

## Product Info
- **Product Page**: https://wiki.dfrobot.com/SKU_SEN0623_C1001_mmWave_Human_Detection_Sensor
- **Integration Reference**: https://github.com/DFRobot/DFRobot_HumanDetection
- **SKU**: SEN0623

## Current Status
- Base protocol: IMPLEMENTED
- Stubs for almost all: IMPLEMENTED

## Task List

### Phase 1: Critical Bugs

- [x] 1.1 Fix crash bug - null pointer dereference when text sensors not configured
  - Location: `dfrobot_sen0623.cpp:328-329`
  - Issue: `status_text_sensor_` and `movement_text_sensor_` accessed without null check
  - Fix: Add null checks before publish_state calls

### Phase 8: Additional Bugs Found During Review

- [ ] 8.1 Duplicate operation code conflict
  - Location: `dfrobot_sen0623.cpp:8` and `dfrobot_sen0623.cpp:20`
  - Issue: `OP_INIT = {0x01, 0x83}` conflicts with `OP_REQ_HP_LED = {0x01, 0x83}` - same code used for different operations
  - Fix: Delete duplicate OP_INIT which is at line 8 and use only once at line 20

- [ ] 8.2 Missing parentheses in bit shift operations
  - Location: Multiple locations in `dfrobot_sen0623.cpp`
  - Issue: `data[0] << 8 | data[1]` should be `(data[0] << 8) | data[1]` for proper precedence
  - Fix: Add parentheses around bit shifts

- [ ] 8.3 set_switch_hp_led uses wrong switch pointer
  - Location: `dfrobot_sen0623.cpp:949`
  - Issue: Uses `request_rate_switch_` instead of `hp_led_switch_`
  - Fix: Replace with correct `hp_led_switch_`

- [ ] 8.4 set_switch_hp_led missing null check
  - Location: `dfrobot_sen0623.cpp:947-964`
  - Issue: No null check before `this->hp_led_switch_->publish_state(val)`
  - Fix: Add null check like other methods

- [ ] 8.5 set_switch_request_rate uses wrong switch pointer
  - Location: `dfrobot_sen0623.cpp:941-944`
  - Issue: Uses `_switch_request_rate` but should use `request_rate_switch_`
  - Fix: Use correct switch variable

- [ ] 8.6 install_angle_y and install_angle_z sensors not handled in process_packet
  - Location: `dfrobot_sen0623.cpp:647-651`
  - Issue: Only x angle is handled, y and z missing
  - Fix: Add handling for y and z angles

### Phase 2: Configuration Sync

- [ ] 2.1 Add setup configuration sync
  - Query current mode from device on startup
  - Sync mode to status_text_sensor
  - Query LED states and sync to switch states
  - Query sensor configuration and sync

### Phase 3: Fall Mode Options

- [ ] 3.1 Add installation angle configuration (dmInstallAngle)
  - Command: 0x06, 0x01
  - Fields: x, y, z angles (16-bit each)

- [ ] 3.2 Add installation height configuration (dmInstallHeight)
  - Command: 0x06, 0x02
  - Fields: height in cm

- [ ] 3.3 Add fall mode configuration (dmFallConfig)
  - 0x83, 0x0D: Fall sensitivity (0-10)
  - 0x83, 0x11: Fall break height
  - 0x83, 0x0A: Residence time
  - 0x83, 0x0B: Residence switch
  - 0x83, 0x0F: Alt time
  - 0x83, 0x13: Report frequency
  - 0x83, 0x14: Report switch
  - 0x83, 0x15: Height ratio switch

- [ ] 3.4 Add fall mode data queries (getFallData)
  - 0x83, 0x81: Fall state
  - 0x83, 0x85: Static residency state
  - 0x83, 0x8B: Static residency switch
  - 0x83, 0x8D: Fall sensitivity
  - 0x83, 0x91: Fall break height
  - 0x83, 0x95: Height ratio switch

- [ ] 3.5 Add track point query
  - 0x83, 0x8E: Track coordinates (x, y)
  - 0x83, 0x93: Track frequency

- [ ] 3.6 Add unmanned time query
  - 0x80, 0x92: Unmanned time

### Phase 4: Sleep Mode Options

- [ ] 4.1 Add sleep mode configuration (configSleep)
  - 0x84, 0x0F: Reporting mode config
  - 0x84, 0x13: Abnormal struggle config
  - 0x84, 0x14: Unattended state config
  - 0x84, 0x15: Unattended time config
  - 0x84, 0x16: Sleep deadline config

- [ ] 4.2 Add sleep mode data queries (smSleepData)
  - 0x84, 0x81: In or not in bed
  - 0x84, 0x82: Sleep state
  - 0x84, 0x83: Wake duration
  - 0x84, 0x84: Light sleep
  - 0x84, 0x85: Deep sleep duration
  - 0x84, 0x86: Sleep quality
  - 0x84, 0x8C: Reporting mode
  - 0x84, 0x8E: Sleep disturbances
  - 0x84, 0x90: Sleep quality rating
  - 0x84, 0x91: Abnormal struggle
  - 0x84, 0x92: Unattended state
  - 0x84, 0x93: Abnormal struggle switch
  - 0x84, 0x94: Unattended switch
  - 0x84, 0x95: Unattended time
  - 0x84, 0x96: Sleep deadline

- [ ] 4.3 Add sleep composite query
  - 0x84, 0x8D: Sleep composite data

- [ ] 4.4 Add sleep statistics query
  - 0x84, 0x8F: Sleep statistics

- [ ] 4.5 Add breath detection
  - 0x81, 0x81: Breathe state
  - 0x81, 0x82: Breathe value

### Phase 5: Missing Protocol Operations

- [ ] 5.1 Handle unhandled operations (lines 257-280)
  - 0x01, 0x01 → 1 byte
  - 0x07, 0x07 → 1 byte
  - 0x80, 0x02-0x05 → various lengths
  - 0x81, 0x01 → 1 byte
  - 0x84, 0x8C-0x96 → sleep mode values

### Phase 6: Data Pooling

- [ ] 6.1 Improve data pooling mechanism
  - Add configurable polling interval
  - Better request scheduling
  - Automatic mode detection

### Phase 7: Data Dump

- [ ] 7.1 Complete debug data dump
  - Better logging of unhandled packets
  - Hex dump utilities

## Protocol Reference

### Packet Format
```
0x53 0x59 [control] [command] [len_H] [len_L] [data...] [checksum] 0x54 0x43
```

### Operations Map

| Control | Command | Description | Data Length |
|---------|---------|-------------|-------------|
| 0x01 | 0x01 | Unknown | 1 |
| 0x01 | 0x02 | Reset | 1 |
| 0x01 | 0x03 | HP LED control | 1 |
| 0x01 | 0x04 | FALL LED control | 1 |
| 0x01 | 0x83 | Initialize | 1 |
| 0x01 | 0x84 | Get LED state | 1 |
| 0x02 | 0x08 | Set mode | 1 |
| 0x02 | 0xA8 | Get mode | 1 |
| 0x06 | 0x01 | Set install angle | 6 |
| 0x06 | 0x81 | Get install angle | 1 |
| 0x06 | 0x02 | Set install height | 2 |
| 0x06 | 0x82 | Get install height | 1 |
| 0x06 | 0x90 | Auto measure height | 1 |
| 0x80 | 0x81 | Human presence | 1 |
| 0x80 | 0x82 | Human movement | 1 |
| 0x80 | 0x83 | Human move range | 1 |
| 0x80 | 0x84 | Human distance | 2 |
| 0x80 | 0x8D | Seated distance | 2 |
| 0x80 | 0x8E | Motion distance | 2 |
| 0x80 | 0x0D | Set seated distance | 2 |
| 0x80 | 0x0E | Set motion distance | 2 |
| 0x80 | 0x92 | Unmanned time | 4 |
| 0x80 | 0x12 | Set unmanned time | 4 |
| 0x81 | 0x81 | Breathe state | 1 |
| 0x81 | 0x82 | Breathe value | 1 |
| 0x83 | 0x81 | Fall state | 1 |
| 0x83 | 0x85 | Static residency state | 1 |
| 0x83 | 0x8A | Static residency time | 4 |
| 0x83 | 0x8B | Static residency switch | 1 |
| 0x83 | 0x8C | Fall time | 4 |
| 0x83 | 0x8D | Fall sensitivity | 1 |
| 0x83 | 0x8E | Track | 2 |
| 0x83 | 0x8F | Accumulated height duration | 4 |
| 0x83 | 0x90 | Fall break height | 2 |
| 0x83 | 0x91 | Auto measure height | 2 |
| 0x83 | 0x93 | Track frequency | 4 |
| 0x83 | 0x94 | Trajectory switch | 1 |
| 0x83 | 0x95 | Height ratio switch | 1 |
| 0x83 | 0x0A | Set residence time | 4 |
| 0x83 | 0x0B | Set residence switch | 1 |
| 0x83 | 0x0C | Set fall time | 4 |
| 0x83 | 0x0D | Set fall sensitivity | 1 |
| 0x83 | 0x0F | Set alt time | 4 |
| 0x83 | 0x11 | Set fall break height | 2 |
| 0x83 | 0x13 | Set report frequency | 4 |
| 0x83 | 0x14 | Set report switch | 1 |
| 0x83 | 0x15 | Set height ratio switch | 1 |
| 0x84 | 0x81 | In or not in bed | 1 |
| 0x84 | 0x82 | Sleep state | 1 |
| 0x84 | 0x83 | Wake duration | 2 |
| 0x84 | 0x84 | Light sleep | 2 |
| 0x84 | 0x85 | Deep sleep | 2 |
| 0x84 | 0x86 | Sleep quality | 1 |
| 0x84 | 0x8C | Reporting mode | 1 |
| 0x84 | 0x8D | Sleep composite | 8 |
| 0x84 | 0x8E | Sleep disturbances | 1 |
| 0x84 | 0x8F | Sleep statistics | 12 |
| 0x84 | 0x90 | Sleep quality rating | 1 |
| 0x84 | 0x91 | Abnormal struggle | 1 |
| 0x84 | 0x92 | Unattended state | 1 |
| 0x84 | 0x93 | Abnormal struggle switch | 1 |
| 0x84 | 0x94 | Unattended switch | 1 |
| 0x84 | 0x95 | Unattended time | 1 |
| 0x84 | 0x96 | Sleep deadline | 1 |
| 0x84 | 0x0F | Set reporting mode | 1 |
| 0x84 | 0x13 | Set abnormal struggle | 1 |
| 0x84 | 0x14 | Set unattended state | 1 |
| 0x84 | 0x15 | Set unattended time | 1 |
| 0x84 | 0x16 | Set sleep deadline | 1 |
| 0x85 | 0x82 | Heart rate | 1 |

## Modes

- **Mode 1**: Fall detection mode
- **Mode 2**: Sleep monitoring mode