#!/bin/bash
ifconfig | grep -oP '(\w\w:\w\w:\w\w:\w\w:\w\w:\w\w)' | uniq
