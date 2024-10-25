array_methods=("bubble" "select" "insert" "shell" "quick" "heap" "merge" "count" "radix")

for method in "$array_methods[@]"
do 
    ./koala "$method" < ./casos_teste/ran21.in >> "$method".out
done