array_methods=("merge" "count")

for method in "$array_methods[@]"
do
    for i in {2..5}
    do
        echo "$method creord $i" 
        ./koala "$method" < ./casos_teste/creord$i.in >> ./dados/"$method"/creord.dat
    done 
done

for method in "$array_methods[@]"
do
    for i in {2..5}
    do
        echo "$method decreord $i" 
        ./koala "$method" < ./casos_teste/decreord$i.in >> ./dados/"$method"/decreord.dat
    done 
done

for method in "$array_methods[@]"
do
    for i in {2..5}
    do
        for j in {1..5}
        do 
            echo "$method rann $i$j" 
            ./koala "$method" < ./casos_teste/ran$i$j.in >> ./dados/"$method"/ran$i.dat
        done 
    done 
done