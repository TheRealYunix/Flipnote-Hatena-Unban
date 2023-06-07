# FlipUnban - DSi Flipnote Studio Unban Tool

## Description

FlipUnban is a command line tool designed to unban Flipnote Studio on a modded DSi. It generates a custom FSID (Flipnote Studio ID) for your DSi, allowing you to access Flipnote Studio even if your console was previously banned.

This tool is intended for use with a modded DSi, Homebrew capabilities, Twilight Menu, and a properly installed Flipnote Studio. Please ensure you meet these requirements before proceeding.

## Requirements

- Modded DSi (with Homebrew capability)
- Twilight Menu
- Flipnote Studio installed under "SDCARD:/roms/dsiware"

## Instructions

1. Locate your `public.sav` file. It can be found in `SDCARD:/roms/dsiware/saves`. The file should have the same name as Flipnote Studio but with a different file extension (Save file from Flipnote Studio).

2. Copy the `public.sav` file (ideally, rename it to `public.sav`) and paste it in the same directory as the `FlipUnban.exe` file. Make a note of the original file name (with the extension).

3. Open the command prompt (CMD) and navigate to the directory where the `FlipUnban.exe` file is located.

4. In the command prompt, type: `FlipUnban.exe -o option.bin public.sav`. This command will generate an `option.bin` file.

5. Run `FlipUnban.exe option.bin`. The FlipUnban tool will generate a custom FSID. Make sure to note down the generated cheat code.

6. Now, execute the command: `FOP.exe option.bin`. This step ensures that the `option.bin` file is checksummed, allowing Flipnote Studio to accept your modified `option.bin` without deleting it.

7. Use the following command: `FlipUnban.exe -i option.bin public.sav`. This command will inject the modified `option.bin` file back into the `public.sav` file.

8. Put the `public.sav` file back into its original location. Remember to rename it to the actual name noted in step 2. This renaming is necessary for Twilight Menu to detect your save file correctly.

9. Open Twilight Menu, go to Flipnote Studio, and you should see your new FSID (Flipnote Studio ID). Press L + D-Pad Down + Select to open NDS-Bootstrap. Navigate to the "RAM-Viewer" and press Y. Enter the generated cheat code and apply the changes.

Done! Your DSi should now be unbanned for Flipnote Studio.

## Troubleshooting

If you encounter any issues during the process, please refer to relevant resources or seek assistance from the Homebrew community. Ensure that you have a modded DSi with Homebrew capabilities, and you have properly installed Twilight Menu and Flipnote Studio.

## Credits

This tool is inspired by Flipnote Hatena and developed by [TheRealYunix](https://github.com/TheRealYunix). Thank you to the Homebrew community for their support and contributions.


**Please note:** Using FlipUnban to unban Flipnote Studio may violate the rules and terms of service of most Flipnote Hatena servers. It is important to understand the potential consequences of using this tool, as it may result in the loss of access to online services or other penalties imposed by the server administrators. Proceed with caution and at your own risk.

It is recommended to use FlipUnban solely for personal and offline use, and to refrain from using it to access online features or sharing Flipnotes on public servers.

The developers of FlipUnban are not responsible for any actions taken against users who violate the rules and terms of service of Flipnote Hatena or any other related servers. Please respect the rules set by the server administrators and use this tool responsibly.
