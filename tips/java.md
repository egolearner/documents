* thread dump中nid转为十进制即linux的tid
```
#492 prio=5 os_prio=0 tid=0x00007fb6fa760000 nid=0x937 sleeping[0x00007fb6dd37c000]
```
* debug maven target https://stackoverflow.com/a/14853683
  1. from the command line, run maven goal with mvnDebug instead of mvn. E.g. mvnDebug clean
  2. Open the source of the maven plugin you want to debug in intelliJ and set a breakPoint
  3. In IDEA, add a Remote JVM Debug Configuration. Under Settings, set Transport: Socket, Debugger Mode: Attach, Host: localhost, Port: 8000 (default port of mvnDebug).
  4. Run the Configuration in Debug mode. It should connect to the waiting mvnDebug jvm.
* gdb java program
```gdb
handle SIGSEGV nostop noprint pass
```
