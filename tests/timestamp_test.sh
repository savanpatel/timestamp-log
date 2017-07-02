#! /bin/sh
cd ../src/ && make && (ls -lrth | ./timestamp -o /tmp/output_file_test.txt -t /tmp/timestamp_file_test.txt);
cd ../src/ && make clean;
timeLines=`wc -l /tmp/output_file_test.txt | cut -d ' ' -f1`;
outLines=`wc -l /tmp/timestamp_file_test.txt | cut -d ' ' -f1`;
rm -rf /tmp/output_file_test.txt;
rm -rf /tmp/timestamp_file_test.txt;

if [ $timeLines -ne $outLines ]
then
  echo "ls test to timestamp log. [Failed]";
  exit 1;
fi
echo "ls test to timestamp log. [Success]";
exit 0;
