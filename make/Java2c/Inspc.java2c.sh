export TMP="../../tmpJava2CJc"
if test $1 = "clean"; then
  rm -f ../source/InspcJ2c/*
  rm -f ../include/InspcJ2c/*
  rm -f ../stc/InspcJ2c/*
fi
if test ! $TMP; then mkdir $TMP; fi
java -ea -cp ../../exe/Java2C.jar org.vishia.java2C.Java2C -cfg=Inspc.java2c.cfg -oc=../source -oh=../include -os=../stc -syntax=../../zbnfjax/zbnf --rlevel:334 --report:$TMP/java2cJc.rpt
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       