# timestamp-log
Tag time stamp to the output of any I/O.

timestamp-log is a utility to tag command output with the time of its occurrence. Pipe command output to the utility with timestamp filename and output filename.
It doesn't change your command's output by keeping timestamp tags into seperate file. 

### Mapping
Mapping time tag to output is simple. timestamp tag at line number `n` maps to output at linn `n`.

## Options
-t: timestamp output file.
-o: output file.

### Usage
`command | ./timestamp -o <outputfile> -t <timestampfile>`


#### example: 
   `ls -lrth | ./timestamp -o lsoutput.txt -t lstimetags.txt`
   
   
   `s3cmd ls -lrth |  ./timestamp -o lsoutput.txt -t lstimetags.txt`
