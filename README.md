# DebugWireDebuggerProgrammer

For details on this project see: https://sites.google.com/site/wayneholder/debugwire3

# NormanDunbar's Changes

* The `LISTxxxx` command is actually, `Lxxxx` and not as the original help text states. Fixed the help text.
* A few minor spelling errors in various comments have been fixed.
* The help text was unsorted and slightly confusing when searching for commands. I've re-ordered the help text to be alphabetical as per the command names. In addition, a few spurious "e" characters have been removed from the end of some "xxxx" and "yyyy" text.
* The new command `SRAM` has been added to display the SRAM base address and size, useful when trying to examine SRAM contents but have forgotten the base address! (Ask me how I know?) 
   ```
   sram
   SRAM:   512 bytes
   SRBase: 0x0060
   ```
