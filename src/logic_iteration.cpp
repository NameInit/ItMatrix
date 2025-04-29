#include "logic_iteration.h"

#ifdef SNAKE
	#ifdef UP
		#define DIRECT_ROW -1
	#else
		#ifdef DOWN
			#define DIRECT_ROW 1
		#else
			#define DIRECT_ROW 0
		#endif
	#endif

	#ifdef LEFT
		#define DIRECT_COL -1
	#else
		#ifdef RIGHT
			#define DIRECT_COL 1
		#else
			#define DIRECT_COL 0
		#endif
	#endif

	int* GetIndRowCol(int num, int size_row, int size_col){
		static int index_row_col[2]={0,0};

		if(DIRECT_ROW==0 && DIRECT_COL==0){
			throw std::logic_error("no direction specified");
		}
		unsigned start_row=-1;
		unsigned start_col=-1;
		int direct_row=DIRECT_ROW;
		int direct_col=DIRECT_COL;
		#ifdef START_ROW
			start_row=0;
		#endif
		#ifdef END_ROW
			start_row=size_row-1;
		#endif
		#ifdef START_COL
			start_col=0;
		#endif
		#ifdef END_COL
			start_col=size_col-1;
		#endif
		if(start_col==-1 || start_row==-1){
			throw std::logic_error("no starting position selected");
		}
		unsigned cur_row=start_row;
		unsigned cur_col=start_col;
		for(int cur_num=0; (cur_num<size_row*size_col)*(cur_num!=num); cur_num++){
			cur_row+=direct_row;
			cur_col+=direct_col;
			if((cur_row==-1)||(cur_row==size_row)||(cur_col==-1)||(cur_col==size_col)){
				cur_row-=direct_row;
				cur_col-=direct_col;
				direct_row*=-1;
				direct_col*=-1;
				if(direct_col==0) cur_col+=(start_col==0) ? 1 : -1; //ходим вверх-вниз
				else if(direct_row==0) cur_row+=(start_row==0) ? 1 : -1; //ходим вправо-влево
			}
		}
		index_row_col[0]=cur_row;
		index_row_col[1]=cur_col;
		return index_row_col;
	}
#endif

#ifdef SNAIL
	#ifdef UP
		#define DIRECT_ROW -1
	#else
		#ifdef DOWN
			#define DIRECT_ROW 1
		#else
			#define DIRECT_ROW 0
		#endif
	#endif

	#ifdef LEFT
		#define DIRECT_COL -1
	#else
		#ifdef RIGHT
			#define DIRECT_COL 1
		#else
			#define DIRECT_COL 0
		#endif
	#endif

	int* GetIndRowCol(int num, int size_row, int size_col){
		if(DIRECT_ROW==0 && DIRECT_COL==0){
			throw std::logic_error("no direction specified");
		}
		unsigned cur_row=-1;
		unsigned cur_col=-1;
		#ifdef START_ROW
			cur_row=0;
		#endif
		#ifdef END_ROW
			cur_row=size_row-1;
		#endif
		#ifdef START_COL
			cur_col=0;
		#endif
		#ifdef END_COL
			cur_col=size_col-1;
		#endif
		if(cur_col==-1 || cur_row==-1){
			throw std::logic_error("no starting position selected");
		}

		static int index_row_col[2]={0,0};
		//ограничиваем улитку в квадрате с динамическими границами
		int start_row=-1;
		int start_col=-1;
		int end_row=size_row;
		int end_col=size_col;
		//
		int direct_row=DIRECT_ROW;
		int direct_col=DIRECT_COL;

		int clockwise=-1; //1 - по часовой, -1 - против часовой
		if(cur_row==0&&cur_col==0&&direct_row==1) clockwise=1;
		else if(cur_row==0&&cur_col==(size_col-1)&&direct_col==-1) clockwise=1;
		else if(cur_row==(size_row-1)&&cur_col==(size_col-1)&&direct_row==-1) clockwise=1;
		else if(cur_row==(size_row-1)&&cur_col==0&&direct_col==1) clockwise=1;

		for(int cur_num=0; (cur_num<size_row*size_col)*(cur_num!=num); cur_num++){
			cur_row+=direct_row;
			cur_col+=direct_col;
			if((cur_row==start_row)||(cur_row==end_row)||(cur_col==start_col)||(cur_col==end_col)){
				if(direct_col!=0){
					if(cur_row==(start_row+1)) start_row+=1;
					else end_row-=1;
				}
				else if(direct_row!=0){
					if(cur_col==(start_col+1)) start_col+=1;
					else end_col-=1;
				}

				cur_row-=direct_row;
				cur_col-=direct_col;

				if(direct_col==0) {
					direct_col=clockwise*direct_row;
					direct_row= 0;
				}
				else if(direct_row==0) {
					direct_row=-clockwise*direct_col;
					direct_col= 0;
				}
				cur_row+=direct_row;
				cur_col+=direct_col;
			}
		}
		index_row_col[0]=cur_row;
		index_row_col[1]=cur_col;
		return index_row_col;
	}

#endif

#ifdef DIAGONAL_SNAKE

	#ifdef UP
		#define DIRECT_ROW -1
	#else
		#ifdef DOWN
			#define DIRECT_ROW 1
		#else
			#define DIRECT_ROW 0
		#endif
	#endif

	#ifdef LEFT
		#define DIRECT_COL -1
	#else
		#ifdef RIGHT
			#define DIRECT_COL 1
		#else
			#define DIRECT_COL 0
		#endif
	#endif

	
#endif


#ifdef REVERSITY_SNAIL
	#ifdef UP
		#define DIRECT_ROW -1
	#else
		#ifdef DOWN
			#define DIRECT_ROW 1
		#else
			#define DIRECT_ROW 0
		#endif
	#endif

	#ifdef LEFT
		#define DIRECT_COL -1
	#else
		#ifdef RIGHT
			#define DIRECT_COL 1
		#else
			#define DIRECT_COL 0
		#endif
	#endif

	int* GetIndRowCol(int num, int size_row, int size_col){
		if(DIRECT_ROW==0 && DIRECT_COL==0){
			throw std::logic_error("no direction specified");
		}
		unsigned cur_row=-1;
		unsigned cur_col=-1;
		#ifdef START_ROW
			cur_row=0;
		#endif
		#ifdef END_ROW
			cur_row=size_row-1;
		#endif
		#ifdef START_COL
			cur_col=0;
		#endif
		#ifdef END_COL
			cur_col=size_col-1;
		#endif
		if(cur_col==-1 || cur_row==-1){
			throw std::logic_error("no starting position selected");
		}
		
		static int index_row_col[2]={0,0};
		//ограничиваем улитку в квадрате с динамическими границами
		int start_row=-1;
		int start_col=-1;
		int end_row=size_row;
		int end_col=size_col;
		//
		int direct_row=DIRECT_ROW;
		int direct_col=DIRECT_COL;
		int count_turn=0;
		int flag=0;

		int clockwise=-1; //1 - по часовой, -1 - против часовой
		if(cur_row==0&&cur_col==0&&direct_row==1) clockwise=1;
		else if(cur_row==0&&cur_col==(size_col-1)&&direct_col==-1) clockwise=1;
		else if(cur_row==(size_row-1)&&cur_col==(size_col-1)&&direct_row==-1) clockwise=1;
		else if(cur_row==(size_row-1)&&cur_col==0&&direct_col==1) clockwise=1;

		for(int cur_num=0; (cur_num<size_row*size_col)*(cur_num!=num); cur_num++){
			if(flag){
				flag=0;
				if(direct_col==0) {
					direct_col=clockwise*direct_row;
					direct_row= 0;
				}
				else if(direct_row==0) {
					direct_row=-clockwise*direct_col;
					direct_col= 0;
				}
				clockwise*=-1;
			}
			// std::cout<<matr[cur_row][cur_col]<<' ';
			// std::cout << matr[cur_row][cur_col] << ' ' << start_row-end_row << ' ' << start_col-end_col << std::endl;
			cur_row+=direct_row;
			cur_col+=direct_col;
			if((cur_row==start_row)||(cur_row==end_row)||(cur_col==start_col)||(cur_col==end_col)){
				if(direct_col!=0){
					if(cur_row==(start_row+1)) start_row+=1;
					else end_row-=1;
				}
				else if(direct_row!=0){
					if(cur_col==(start_col+1)) start_col+=1;
					else end_col-=1;
				}

				cur_row-=direct_row;
				cur_col-=direct_col;

				if(direct_col==0) {
					direct_col=clockwise*direct_row;
					direct_row= 0;
				}
				else if(direct_row==0) {
					direct_row=-clockwise*direct_col;
					direct_col= 0;
				}
				count_turn+=1;
				if(count_turn%4==0) flag=1;
				cur_row+=direct_row;
				cur_col+=direct_col;
			}
		}
		index_row_col[0]=cur_row;
		index_row_col[1]=cur_col;
		return index_row_col;
	}
#endif