# Hashes a file, ignoring all whitespace and comments. Use for
# verifying that code was correctly typed.
cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum |cut -c-6

# bash hash.sh arquivo.cpp l1 l2 (hash of lines [l1, l2]):
sed -n $2','$3' p' $1 | sed '/^#w/d' | cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6