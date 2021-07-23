* `ping -f`检测网络丢包，要求有root权限。
>     -f      Flood ping.  Outputs packets as fast as they come back or one hundred times per second, whichever is more.  For every
>             ECHO_REQUEST sent a period ``.'' is printed, while for every ECHO_REPLY received a backspace is printed.  This provides a rapid
>             display of how many packets are being dropped.  Only the super-user may use this option.  This can be very hard on a network and
>             should be used with caution.

* `dig +short hostname` convert hostname to ip
* `numactl --hardware` show numa information
* move running process to tmux/screen
  1. Suspend the respective process with `Ctrl-Z`
  1. Send the job to background using `bg`
  1. Take away the ownership from the shell using `disown`
  1. Start or enter your tmux/screen session
  1. Run `reptyr PID` to attach the process to the current shell（`reptyr -T PID` if process has subprocess)
