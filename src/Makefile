var1= -DDOWN -DSTART_ROW -DSTART_COL

main: var1 var2 var3 var4 var5 var6 var7 var8 var9 var10 var11 var12 var13 var14 var15 var16 var25 var26 var27 var28 var29 var30 var31 var32

test: test.cpp logic_iteration.cpp
	g++ ${var1} test.cpp logic_iteration.cpp

var1: main.cpp logic_iteration.cpp
	g++ -o var1 -DSNAKE -DDOWN -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var2: main.cpp logic_iteration.cpp
	g++ -o var2 -DSNAKE -DRIGHT -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var3: main.cpp logic_iteration.cpp
	g++ -o var3 -DSNAKE -DDOWN -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var4: main.cpp logic_iteration.cpp
	g++ -o var4 -DSNAKE -DLEFT -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var5: main.cpp logic_iteration.cpp
	g++ -o var5 -DSNAKE -DUP -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var6: main.cpp logic_iteration.cpp
	g++ -o var6 -DSNAKE -DRIGHT -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var7: main.cpp logic_iteration.cpp
	g++ -o var7 -DSNAKE -DUP -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

var8: main.cpp logic_iteration.cpp
	g++ -o var8 -DSNAKE -DLEFT -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

var9: main.cpp logic_iteration.cpp
	g++ -o var9 -DSNAIL -DDOWN -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var10: main.cpp logic_iteration.cpp
	g++ -o var10 -DSNAIL -DRIGHT -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var11: main.cpp logic_iteration.cpp
	g++ -o var11 -DSNAIL -DDOWN -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var12: main.cpp logic_iteration.cpp
	g++ -o var12 -DSNAIL -DLEFT -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var13: main.cpp logic_iteration.cpp
	g++ -o var13 -DSNAIL -DUP -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var14: main.cpp logic_iteration.cpp
	g++ -o var14 -DSNAIL -DRIGHT -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var15: main.cpp logic_iteration.cpp
	g++ -o var15 -DSNAIL -DUP -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

var16: main.cpp logic_iteration.cpp
	g++ -o var16 -DSNAIL -DLEFT -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

var25: main.cpp logic_iteration.cpp
	g++ -o var25 -DREVERSITY_SNAIL -DDOWN -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var26: main.cpp logic_iteration.cpp
	g++ -o var26 -DREVERSITY_SNAIL -DRIGHT -DSTART_ROW -DSTART_COL main.cpp logic_iteration.cpp

var27: main.cpp logic_iteration.cpp
	g++ -o var27 -DREVERSITY_SNAIL -DDOWN -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var28: main.cpp logic_iteration.cpp
	g++ -o var28 -DREVERSITY_SNAIL -DLEFT -DSTART_ROW -DEND_COL main.cpp logic_iteration.cpp

var29: main.cpp logic_iteration.cpp
	g++ -o var29 -DREVERSITY_SNAIL -DUP -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var30: main.cpp logic_iteration.cpp
	g++ -o var30 -DREVERSITY_SNAIL -DRIGHT -DEND_ROW -DSTART_COL main.cpp logic_iteration.cpp

var31: main.cpp logic_iteration.cpp
	g++ -o var31 -DREVERSITY_SNAIL -DUP -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

var32: main.cpp logic_iteration.cpp
	g++ -o var32 -DREVERSITY_SNAIL -DLEFT -DEND_ROW -DEND_COL main.cpp logic_iteration.cpp

clear:
	rm -f var[1-9] var[1-3][0-9] a.out