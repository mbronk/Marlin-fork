# Where have all the configurations gone?

Marlin configurations for specific machines are now maintained in their own repository at:

## https://github.com/MarlinFirmware/Configurations/tree/2.1.3-b3

Configuration files for use with the nightly `bugfix-2.1.x` branch can be downloaded from:

## https://github.com/MarlinFirmware/Configurations/archive/bugfix-2.1.x.zip


# USAGE (SPRO)
0. CD to submodule dir
1. Update submodule from origin (https://github.com/MarlinFirmware/Configurations) `git submodule update --remote` + `git fetch upstream --tags`
2. Checkout matching release tag (e.g. 2.1.2) as SapphirePRO/2.1.2 `git checkout -b SapphirePRO/2.1.3-b1 tags/2.1.3-b1` + `git push --set-upstream origin SapphirePRO/2.1.3-b1`
3. Update submodule... `commit?`
4. Diff 
   > & 'C:\Program Files\Beyond Compare 4\BComp.exe' '.\config\MarlinFirmware_Configurations-fork\config\examples\Two Trees\Sapphire Pro\Configuration.h' .\Marlin\Configuration.h

   > & 'C:\Program Files\Beyond Compare 4\BComp.exe' '.\config\MarlinFirmware_Configurations-fork\config\examples\Two Trees\Sapphire Pro\Configuration_adv.h' .\Marlin\Configuration_adv.h
