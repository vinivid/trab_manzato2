for i in {2..5}
do 
    echo 'bubble creord' $i
    ./koala bubble < ./casos_teste/creord$i.in >> ./dados/bubble/creord.dat
done

for i in {2..5}
do 
    echo 'select creord' $i
    ./koala select < ./casos_teste/creord$i.in >> ./dados/select/creord.dat
done

for i in {2..5}
do  
    echo 'insert creord' $i
    ./koala insert < ./casos_teste/creord$i.in >> ./dados/insert/creord.dat
done

for i in {2..5}
do 
    echo 'shell creord' $i
    ./koala shell < ./casos_teste/creord$i.in >> ./dados/shell/creord.dat
done

for i in {2..5}
do 
    echo 'quick creord' $i
    ./koala quick < ./casos_teste/creord$i.in >> ./dados/quick/creord.dat
done

for i in {2..5}
do 
    echo 'heap creord' $i
    ./koala heap < ./casos_teste/creord$i.in >> ./dados/heap/creord.dat
done

for i in {2..5}
do 
    echo 'merge creord' $i
    ./koala merge < ./casos_teste/creord$i.in >> ./dados/merge/creord.dat
done

for i in {2..5}
do
    echo 'count creord' $i
    ./koala count < ./casos_teste/creord$i.in >> ./dados/count/creord.dat
done

for i in {2..5}
do 
    echo 'radix creord' $i
    ./koala radix < ./casos_teste/creord$i.in >> ./dados/radix/creord.dat
done

#Ordem decrescente
for i in {2..5}
do 
    echo 'bubble decreord' $i
    ./koala bubble < ./casos_teste/decreord$i.in >> ./dados/bubble/decreord.dat
done

for i in {2..5}
do 
    echo 'select decreord' $i
    ./koala select < ./casos_teste/decreord$i.in >> ./dados/select/decreord.dat
done

for i in {2..5}
do 
    echo 'insert decreord' $i
    ./koala insert < ./casos_teste/decreord$i.in >> ./dados/insert/decreord.dat
done

for i in {2..5}
do 
    echo 'shell decreord' $i
    ./koala shell < ./casos_teste/decreord$i.in >> ./dados/shell/decreord.dat
done

for i in {2..5}
do 
    echo 'quick decreord' $i
    ./koala quick < ./casos_teste/decreord$i.in >> ./dados/quick/decreord.dat
done

for i in {2..5}
do 
    echo 'heap decreord' $i
    ./koala heap < ./casos_teste/decreord$i.in >> ./dados/heap/decreord.dat
done

for i in {2..5}
do 
    echo 'merge decreord' $i
    ./koala merge < ./casos_teste/decreord$i.in >> ./dados/merge/decreord.dat
done

for i in {2..5}
do 
    echo 'count decreord' $i
    ./koala count < ./casos_teste/decreord$i.in >> ./dados/count/decreord.dat
done

for i in {2..5}
do
    echo 'radix decreord' $i
    ./koala radix < ./casos_teste/decreord$i.in >> ./dados/radix/decreord.dat
done

#Randomicos
for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala bubble < ./casos_teste/ran$j$i.in >> ./dados/bubble/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala select < ./casos_teste/ran$j$i.in >> ./dados/select/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala insert < ./casos_teste/ran$j$i.in >> ./dados/insert/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala shell < ./casos_teste/ran$j$i.in >> ./dados/shell/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala quick < ./casos_teste/ran$j$i.in >> ./dados/quick/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala heap < ./casos_teste/ran$j$i.in >> ./dados/heap/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala merge < ./casos_teste/ran$j$i.in >> ./dados/merge/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala count < ./casos_teste/ran$j$i.in >> ./dados/count/ran$j.dat
    done 
done 

for i in {1..5}
do 
    for j in {2..5}
    do 
        ./koala radix < ./casos_teste/ran$j$i.in >> ./dados/radix/ran$j.dat
    done 
done 