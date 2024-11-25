# Networking commands
## Table of Contents
<details>
<summary>As a list form</summary>

1. [ipconfig/ifconfig](#1-ipconfigifconfig)
2. [ping](#2-ping)
3. [nslookup](#3-nslookup)
4. [hostname](#4-hostname)
5. [netstat](#5-netstat)
6. [nbtstat](#6-nbtstat)
7. [net](#7-net)
8. [tracert/traceroute](#8-tracerttraceroute)
9. [arp](#9-arp)
10. [getmac](#10-getmac)
11. [pathping](#11-pathping)
12. [route](#12-route)

</details>

Heading | Link
-- | --
Ipconfig | [ipconfig/ifconfig](#1-ipconfigifconfig)
Ping | [ping](#2-ping)
Nslookup | [nslookup](#3-nslookup)
Hostname | [hostname](#4-hostname)
Netstat | [netstat](#5-netstat)
Nbtstat | [nbtstat](#6-nbtstat)
Net | [net](#7-net)
Tracert | [tracert/traceroute](#8-tracerttraceroute)
Arp | [arp](#9-arp)
Getmac | [getmac](#10-getmac)
Pathping | [pathping](#11-pathping)
Route | [route](#12-route)

## 1. `ipconfig/ifconfig`
- Displays all network configurations across components.
- Can view IPv4, IPv6 Addresses

```cmd
ipconfig
```
Parameters | Description
-- | --
/all | Displays detailed information about all network interfaces.
/release | Releases the IPv4 address for the specified adapter.
/renew | Renews the IPv4 address for the specified adapter.
/flushdns | Purges the DNS Resolver cache.

## 2. `ping`
- Primarily used to troubleshoot connectivity issues.
- Sends ICMP Echo Request packets to the target host and waits for a response.

```cmd
ping google.com
```
Parameters | Description
-- | --
-t | Ping the specified host until stopped.
-i | TTL (Time to Live) value.
-n | Number of Echo Requests to send.
-l | Size of the packet.

## 3. `nslookup`
- Used to query DNS to obtain domain name or IP address mapping.

```cmd
nslookup google.com
```

## 4. `hostname`
- Displays the hostname of the computer.

```cmd
hostname
```

## 5. `netstat`
- Displays active network connections, routing tables, etc.

```cmd
netstat
```
Parameters | Description
-- | --
-a | Displays all connections and listening ports.
-n | Displays addresses and port numbers in numerical form.
-b | Displays the executable involved in creating each connection or listening port.
-o | Displays the owning process ID associated with each connection.

## 6. `nbtstat`
- Displays NetBIOS over TCP/IP protocol statistics.

```cmd
nbtstat
```
Parameters | Description
-- | --
-a | Lists the NetBIOS name table for the remote computer.
-A | Lists the NetBIOS name table for the remote computer, with the IP address.
-c | Lists the contents of the NetBIOS name cache.
-n | Lists the NetBIOS name table of the local computer.
-N | Lists the NetBIOS name table of the local computer, with the IP address.

## 7. `net`
- Used to manage network resources.

```cmd
net view
```
Parameters | Description
-- | --
view | Displays a list of domains, computers, or resources that are being shared by the specified computer.
start | Starts a service.
stop | Stops a service.

## 8. `tracert/traceroute`
- Displays the route taken by packets across an IP network.

```cmd
tracert google.com
```
Parameters | Description
-- | --
-d | Do not resolve addresses to hostnames.
-h | Maximum number of hops to search for target.
-w | Wait time for each reply.

## 9. `arp`
- ARP stands for Address Resolution Protocol.
- Used to view and modify the ARP table.

```cmd
arp -a
```
Parameters | Description
-- | --
-a | Displays the ARP table.

## 10. `getmac`
- Displays the MAC address of the network adapter.

```cmd
getmac
```

## 11. `pathping`
- Combines the functionality of `ping` and `tracert`.

```cmd
pathping google.com
```

## 12. `route`
- Used to view and modify the IP routing table.

```cmd
route print
```
Parameters | Description
-- | --
print | Displays the IP routing table.
