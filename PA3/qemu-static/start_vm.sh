#!/bin/sh


#TODO: Update the following path to point to the disk image
#on your machine
disk_image=/home/rohit/vmimage/base-image-full-32GB.img 
#path to operating system disk image, you need to provide the path

### Do not Edit the following lines ###

qemu_binary=./qemu-system-x86_64  # path to qemu binary
RAM_SIZE=4096  # RAM size for VM in MB.
n_cpu=2  #number of cpu to be used in VM.
kernel=./bzImage

#NOTE: Use the following command to login.
# echo "ssh -p 5555 <user>@localhost"

#TODO: Update the 'root=/dev/sda5' appropriately on your setup

#Follow these steps to set "root=xxx" in your system
#Boot your VM using your existing method (libvirt, virsh...) , run lsblk
#Note down the root partition, shut down the VM

$qemu_binary -L pc-bios -enable-kvm -m $RAM_SIZE -smp $n_cpu -device e1000,netdev=net0 -device cryptcard -netdev user,id=net0,hostfwd=tcp::5555-:22 -kernel $kernel -append 'console=tty0 console=ttyS0 root=/dev/sda2' --nographic -drive format=raw,file=$disk_image
