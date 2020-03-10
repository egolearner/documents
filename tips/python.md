* run cmd, get exit code, output and error
```python
    pipes = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE, shell=True)
    std_out, std_err = pipes.communicate()
    return pipes.returncode, std_out, std_err
```
* convert archive python package to wheel
```bash
pip wheel foo.tar.gz
```
