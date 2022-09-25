while true;do
./rand > tmp.in
./main < tmp.in > main.out
./test < tmp.in > test.out
if diff main.out test.out; then
printf AC
else
echo WA
exit 0
fi
done