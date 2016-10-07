#!/bin/bash
echo "Executing simulation..."
cmake .. >../.junk
make run >../.junk
grep 'FINAL ' -A1 ../.junk 
cmake .. >../.junk
