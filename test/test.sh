CONTAINER=$1

if [ $# != 1 ]
then
    echo "Usage: ./test.sh <container name>";
    exit 1;
fi

make ${CONTAINER} && ./${CONTAINER} 42;
