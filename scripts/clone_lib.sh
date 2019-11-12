#!/bin/bash
usage="Usage: ./clone_lib.sh
Fetch the RawSalmonEngine repo at a specific commit"

commit="0e353fd470abdb767a93fef3a1cb1c9f438c01ab"

if [ "$1" ==  "--help" ] || [ "$1" == "-h" ]
then
    echo "$usage"
    exit
fi

cd "$(dirname "${BASH_SOURCE[0]}")"
cd ../
git clone --recurse-submodules https://github.com/AgoutiGames/RawSalmonEngine.git
cd ./RawSalmonEngine
git checkout ${commit}
echo "Successfully cloned RawSalmonLib!"