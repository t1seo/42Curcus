#!/bin/sh
ifconfig -a | grep ether | grep -v autoselect | awk '{print $2}'