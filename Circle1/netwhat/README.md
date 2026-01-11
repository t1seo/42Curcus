# Netwhat

## Project Overview

Netwhat is a project for learning and evaluating basic networking knowledge. It is assessed through network-related quizzes without any coding involved.

## Study Topics

### 1. IP Address

#### IPv4
- 32-bit address (4 octets of 8 bits each)
- Format: `xxx.xxx.xxx.xxx` (each octet is 0-255)
- Example: `192.168.1.1`

#### IPv6
- 128-bit address
- Format: 8 blocks of 16 bits (separated by colons)
- Example: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`

### 2. Subnet Mask

Distinguishes between network and host portions.

| CIDR | Subnet Mask | Number of Hosts |
|------|-------------|-----------------|
| /24 | 255.255.255.0 | 254 |
| /25 | 255.255.255.128 | 126 |
| /26 | 255.255.255.192 | 62 |
| /27 | 255.255.255.224 | 30 |
| /28 | 255.255.255.240 | 14 |
| /29 | 255.255.255.248 | 6 |
| /30 | 255.255.255.252 | 2 |

### 3. IP Address Classes

| Class | Range | Default Subnet |
|-------|-------|----------------|
| A | 1.0.0.0 - 126.255.255.255 | 255.0.0.0 |
| B | 128.0.0.0 - 191.255.255.255 | 255.255.0.0 |
| C | 192.0.0.0 - 223.255.255.255 | 255.255.255.0 |

### 4. Private IP Addresses

- Class A: `10.0.0.0` - `10.255.255.255`
- Class B: `172.16.0.0` - `172.31.255.255`
- Class C: `192.168.0.0` - `192.168.255.255`

### 5. OSI 7 Layers

| Layer | Name | Protocol Examples |
|-------|------|-------------------|
| 7 | Application | HTTP, FTP, SMTP |
| 6 | Presentation | SSL, JPEG |
| 5 | Session | NetBIOS |
| 4 | Transport | TCP, UDP |
| 3 | Network | IP, ICMP |
| 2 | Data Link | Ethernet, MAC |
| 1 | Physical | Cables, Hubs |

### 6. TCP vs UDP

| Property | TCP | UDP |
|----------|-----|-----|
| Connection | Connection-oriented | Connectionless |
| Reliability | Guaranteed | Not guaranteed |
| Order | Guaranteed | Not guaranteed |
| Speed | Slower | Faster |
| Use Cases | Web, Email | Streaming, DNS |

### 7. DHCP (Dynamic Host Configuration Protocol)

Protocol that automatically assigns IP addresses to clients.

### 8. DNS (Domain Name System)

System that translates domain names to IP addresses.

## Calculation Examples

### Network Address Calculation
```
IP: 192.168.1.130
Subnet: /26 (255.255.255.192)

Network Address: 192.168.1.128
Broadcast: 192.168.1.191
Usable Hosts: 192.168.1.129 - 192.168.1.190 (62 hosts)
```

### Host Count Calculation
```
Hosts = 2^(32-CIDR) - 2
/26 → 2^(32-26) - 2 = 2^6 - 2 = 64 - 2 = 62
```

## Assessment Format

- Online quiz format
- Network fundamentals questions
- IP calculation problems
