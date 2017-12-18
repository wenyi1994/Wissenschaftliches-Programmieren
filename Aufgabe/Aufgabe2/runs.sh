
for i in $(seq 1 3)

do

echo "start with file: start${i}A.dat"
echo -e "\n"

./convergency < start${i}A.dat
echo -e "\n"
echo "finish!"
echo -e "\n"

done

for i in $(seq 1 2)

do

echo "start with file: start${i}B.dat"
echo -e "\n"

./convergency < start${i}B.dat
echo -e "\n"
echo "finish!"
echo -e "\n"

done

echo "
    load 'plot.gp'
    " | gnuplot

# $convert output_image.ps output_image.jgp