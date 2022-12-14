# What is this?

I have a problem... Not a very common problem I think. So let me explain.

## The problem

Setup: My workstation is a VM, not a real computer. I run it on my home server where I use Proxmox to virtualize my stuff (NAS, Router, DNS, Plex, Kubernetes, etc.). I added a GPU and USB controller that I pass directly to the VM to make it a "real computer".

This means I cannot turn it on unless I have another device to access the Proxmox web UI and start the VM. You can set Proxmox to auto start the VM on boot (and it works), but this means I would have to power cycle my whole server just to turn on my workstation after I (or stupid windows update) turn it off.

## The solution

This is **the most over-engineered power button in the world** (to my knowledge). It has 2 components: a simple HTTP server that runs on the Proxmox node as a `systemd` service and a very basic board with an `ESP32` MCU and a button.

The `ESP32` connects to my home wifi and waits for the button to pe pressed. When the button is pressed, it makes a HTTP call to the server that runs on the Proxmox node. The server then issues a `qm start` command to boot the VM.

The hardware assembly is very basic. Just a board with a button and an `ESP32` dev kit. It is powered via USB. I also made a 3d printed box to enclose it, but got bored after I designed the bottom and just used electrical tape for the top.

You can see it in action [here](https://www.youtube.com/watch?v=elHgTOnZTQk).

![Final product photo](/media/photo.jpg?raw=true "The final product")
