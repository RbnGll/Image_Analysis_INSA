#!/bin/bash
echo "Cleaning the image result directory"
rm ../ImageResult/accident/*
rm ../ImageResult/bomb/*
rm ../ImageResult/car/*
rm ../ImageResult/casualty/*
rm ../ImageResult/electricity/*
rm ../ImageResult/fire/*
rm ../ImageResult/firebrigade/*
rm ../ImageResult/flood/*
rm ../ImageResult/gas/*
rm ../ImageResult/injury/*
rm ../ImageResult/paramedics/*
rm ../ImageResult/person/*
rm ../ImageResult/police/*
rm ../ImageResult/rodeblock/*
rm ../ImageResult/UnclassifiedIcons
rm ../ImageResult/ClassifiedIcons
for i in 0 1 2 3 4 5 6 7 8 9
    do
        rm ../ImageResult/Unclassified/00${i}/*
    done
for i in 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
    do
        rm ../ImageResult/Unclassified/0${i}/*
    done