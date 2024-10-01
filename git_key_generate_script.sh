# !/bin/bash

echo "Github key generator script"

#See if there are existing keys 
echo $(ls -al ~/.ssh)

#Generate keys
echo $(ssh-keygen -t ed25519 -C "alu0101545820@ull.edu.es") #"email"
#Alternative
#echo $(ssh-keygen -t rsa -b 4096 -C "alu0101545820@ull.edu.es") 

#Checks correct creation 
echo $(ls -al ~/.ssh)

#Adds key to the ssh agent
echo $(eval "$(ssh-agent -s)") 

echo $(ssh-add ~/.ssh/id_ed25519)

#Key that needs to be copied to github
echo $(cat ~/.ssh/id_ed25519.pub) 