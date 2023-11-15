# 

<div align="center">
<pre>
  ______                            ______         __       __            __     __          
 /      \                          /      \       |  \     /  \          |  \   |  \         
|  ▓▓▓▓▓▓\__    __ _______        |  ▓▓▓▓▓▓\      | ▓▓\   /  ▓▓ ______  _| ▓▓_   \▓▓ _______ 
| ▓▓___\▓▓  \  |  \       \ ______| ▓▓  | ▓▓______| ▓▓▓\ /  ▓▓▓|      \|   ▓▓ \ |  \/       \
 \▓▓    \| ▓▓  | ▓▓ ▓▓▓▓▓▓▓\      \ ▓▓  | ▓▓      \ ▓▓▓▓\  ▓▓▓▓ \▓▓▓▓▓▓\\▓▓▓▓▓▓ | ▓▓  ▓▓▓▓▓▓▓
 _\▓▓▓▓▓▓\ ▓▓  | ▓▓ ▓▓  | ▓▓\▓▓▓▓▓▓ ▓▓  | ▓▓\▓▓▓▓▓▓ ▓▓\▓▓ ▓▓ ▓▓/      ▓▓ | ▓▓ __| ▓▓ ▓▓      
|  \__| ▓▓ ▓▓__/ ▓▓ ▓▓  | ▓▓      | ▓▓__/ ▓▓      | ▓▓ \▓▓▓| ▓▓  ▓▓▓▓▓▓▓ | ▓▓|  \ ▓▓ ▓▓_____ 
 \▓▓    ▓▓\▓▓    ▓▓ ▓▓  | ▓▓       \▓▓    ▓▓      | ▓▓  \▓ | ▓▓\▓▓    ▓▓  \▓▓  ▓▓ ▓▓\▓▓     \
  \▓▓▓▓▓▓  \▓▓▓▓▓▓ \▓▓   \▓▓        \▓▓▓▓▓▓        \▓▓      \▓▓ \▓▓▓▓▓▓▓   \▓▓▓▓ \▓▓ \▓▓▓▓▓▓▓
                                                                                             
                                                                                             
                                                                                             
---------------------------------------------------
A minimalist curtain automator developed by the Group 1 of ELEC-C9801 (DT&EP).
</pre>

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
</div>

## Design Log
Current design log can be found in the [Google Document](https://docs.google.com/document/d/1mjjf6JOW-FxNi6zfv7sWbO6NmfYAhc-9kSr-jBfGe_k/edit?pli=1#heading=h.dk2mgb12e9xe)
## To-do's
- [x] Powering the Arduino and motor with the batteries
- [ ] Finish the mobile app
- [x] Readopting source code for Arduino for HC-06
- [ ] Refactor documentation
    1. Multifile tree


## Protocol
[i]nincialitation => Mobile sends time and Arduino sends schedule
[w]rite => Mobile sends whole schedule
