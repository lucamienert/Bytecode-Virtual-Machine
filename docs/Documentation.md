# Documentation

## Flow Chart

This Chart explains the flow of an File

```mermaid
stateDiagram-v2
    [*] --> .lvm
    .lvm --> Compiler
    Compiler --> .lvmc
    .lvmc --> VirtualMachine
    VirtualMachine --> Interpreted
    Interpreted --> [*]
```
