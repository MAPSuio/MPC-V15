cat wordsEn.txt | shuf | head -n 33781 > random.txt
cat wordsEn.txt random.txt | shuf > final.txt
cat final.txt | sort | uniq | wc -l > answer.txt
