#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

class panel{
public:
    panel();
    ~panel();
    void clearSpace();
    void firstStone();
    void putPlayer1(int a,int b);
    void putPlayer2(int a,int b);
    int whowin();
    void showpanel();
    string Gospace[19][19];
    int i,j;

};

panel::panel(){
    }
    panel::~panel(){
    }
    void panel::clearSpace(){
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                this->Gospace[i][j] = "+";
            }
        }
    }
    void panel::firstStone(){
        this->Gospace[9][9] = "1";
    }
    void panel::putPlayer1(int a,int b){

        this->Gospace[a+9][b+9] = "1";

    }
    void panel::putPlayer2(int a,int b){

        this->Gospace[a+9][b+9] = "2";

    }
    int panel::whowin(){
        int winwho=0;
        for(this->i = 0;this->i < 15;this->i++){
            for(this->j = 0;this->j < 15;this->j++){
                if(this->Gospace[i][j] == "1" && this->Gospace[i+1][j+1] == "1" && this->Gospace[i+2][j+2] == "1" && this->Gospace[i+3][j+3] == "1" && this->Gospace[i+4][j+4] == "1"){
                    winwho = 1;
                }
                if(this->Gospace[i+4][j] == "1" && this->Gospace[i+3][j+1] == "1" && this->Gospace[i+2][j+2] == "1" && this->Gospace[i+1][j+3] == "1" && this->Gospace[i][j+4] == "1"){
                    winwho = 1;
                }
            }
        }
        for(this->i = 0;this->i < 15;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                if(this->Gospace[i][j] == "1" && this->Gospace[i+1][j] == "1" && this->Gospace[i+2][j] == "1" && this->Gospace[i+3][j] == "1" && this->Gospace[i+4][j] == "1"){
                    winwho = 1;
                }
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 15;this->j++){
                if(this->Gospace[i][j] == "1" && this->Gospace[i][j+1] == "1" && this->Gospace[i][j+2] == "1" && this->Gospace[i][j+3] == "1" && this->Gospace[i][j+4] == "1"){
                    winwho = 1;
                }
            }
        }


        for(this->i = 0;this->i < 15;this->i++){
            for(this->j = 0;this->j < 15;this->j++){
                if(this->Gospace[i][j] == "2" && this->Gospace[i+1][j+1] == "2" && this->Gospace[i+2][j+2] == "2" && this->Gospace[i+3][j+3] == "2" && this->Gospace[i+4][j+4] == "2"){
                    winwho = 2;
                }
                if(this->Gospace[i+4][j] == "2" && this->Gospace[i+3][j+1] == "2" && this->Gospace[i+2][j+2] == "2" && this->Gospace[i+1][j+3] == "2" && this->Gospace[i][j+4] == "2"){
                    winwho = 2;
                }
            }
        }
        for(this->i = 0;this->i < 15;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                if(this->Gospace[i][j] == "2" && this->Gospace[i+1][j] == "2" && this->Gospace[i+2][j] == "2" && this->Gospace[i+3][j] == "2" && this->Gospace[i+4][j] == "2"){
                    winwho = 2;
                }
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 15;this->j++){
                if(this->Gospace[i][j] == "2" && this->Gospace[i][j+1] == "2" && this->Gospace[i][j+2] == "2" && this->Gospace[i][j+3] == "2" && this->Gospace[i][j+4] == "2"){
                    winwho = 2;
                }
            }
        }
        return winwho;
    }
void panel::showpanel(){
    for(this->i = 0;this->i < 19;this->i++){
        for(this->j = 0;this->j < 18;this->j++){
            cout << Gospace[i][j];
        }
        cout << Gospace[i][18] << endl;
    }
}

class AImesh{
public:
    AImesh();
    virtual ~AImesh();
    void initalRandom();
    void trans_from(panel* a);
    void calculate();
    void geneInherit(AImesh* Father,AImesh* Mother);
    void predict();
    void mutate();
    int i,j,k,l;
    int X,Y;
    int playernum;
    double input[19][19];
    double hiddenlayerONE[19][19];
    double hiddenlayerTWO[19][19];
    double hiddenlayerTRE[19][19];
    double hiddenlayerFOR[19][19];
    double hiddenlayerFIV[19][19];
    double policylayer[19][19];
    double hiddenlayer_tres_A[19][19];
    double policylayer_tres_A[19][19][6];
    double hiddenlayer_line_A[361][361];
    double policylayer_line_A[361][361][6];
    double hiddenlayer_tres_B[19][19];
    double policylayer_tres_B[19][19][6];
    double hiddenlayer_line_B[361][361];
    double policylayer_line_B[361][361][6];


};

AImesh::AImesh(){
    }
    AImesh::~AImesh(){
    }
    void AImesh::initalRandom(){
        int a;
        double b;
        srand(time(NULL));
        for(this->i = 0;this->i<19;this->i++){
            for(this->j = 0;this->j<19;this->j++){
                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_tres_A[i][j] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][0] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][1] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][2] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][3] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][4] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][5] = b/8192;


                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_tres_B[i][j] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][0] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][1] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][2] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][3] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][4] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][5] = b/8192;



            }
        }
        srand(time(NULL));
        for(this->i = 0;this->i<361;this->i++){
            for(this->j = 0;this->j<361;this->j++){
                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_line_A[i][j] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][0] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][1] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][2] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][3] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][4] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][5] = b/8192;


                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_line_B[i][j] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][0] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][1] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][2] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][3] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][4] = b/8192;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][5] = b/8192;


            }
        }
    }

    void AImesh::trans_from(panel* a){
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                if(a->Gospace[i][j] == "+"){
                    this->input[i][j] = 0;
                }else if(a->Gospace[i][j] == "1"){
                    this->input[i][j] = 1;
                }else if(a->Gospace[i][j] == "2"){
                    this->input[i][j] = -1;
                }
            }
        }
    }
    void AImesh::calculate(){
        int targnum,sum,nodenum;
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->input[k][l]*this->hiddenlayer_line_A[targnum][nodenum];
                    }
                }
                this->hiddenlayerONE[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->hiddenlayerONE[k][l]*this->hiddenlayer_line_A[targnum][nodenum];
                    }
                }
                this->hiddenlayerTWO[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->hiddenlayerTWO[k][l]*this->hiddenlayer_line_A[targnum][nodenum];
                    }
                }
                this->hiddenlayerTRE[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->hiddenlayerTRE[k][l]*this->hiddenlayer_line_A[targnum][nodenum];
                    }
                }
                this->hiddenlayerFOR[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->hiddenlayerFOR[k][l]*this->hiddenlayer_line_A[targnum][nodenum];
                    }
                }
                this->hiddenlayerFIV[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 19;this->j++){
                sum = 0;
                targnum = i*19 + j;
                for(this->k = 0;this->k < 19;this->k++){
                    for(this->l = 0;this->l < 19;this->l++){
                        nodenum = i*19 + j;
                        sum += this->input[k][l]*this->policylayer_line_A[targnum][nodenum][0];
                        sum += this->hiddenlayerONE[k][l]*this->policylayer_line_A[targnum][nodenum][1];
                        sum += this->hiddenlayerTWO[k][l]*this->policylayer_line_A[targnum][nodenum][2];
                        sum += this->hiddenlayerTRE[k][l]*this->policylayer_line_A[targnum][nodenum][3];
                        sum += this->hiddenlayerFOR[k][l]*this->policylayer_line_A[targnum][nodenum][4];
                        sum += this->hiddenlayerFIV[k][l]*this->policylayer_line_A[targnum][nodenum][5];
                    }
                }
                this->policylayer[i][j] = tanh(sum + this->hiddenlayer_tres_A[i][j]);
            }
        }


    }
    void AImesh::geneInherit(AImesh*Father,AImesh*Mother){
        for(this->i = 0;this->i < 361;this->i++){
            for(this->j = 0;this->j < 361;this->j++){
                this->hiddenlayer_line_A[i][j] = Father->hiddenlayer_line_A[i][j];
                this->hiddenlayer_line_B[i][j] = Mother->hiddenlayer_line_B[i][j];
                this->policylayer_line_A[i][j][0] = Father->policylayer_line_A[i][j][0];
                this->policylayer_line_B[i][j][0] = Mother->policylayer_line_B[i][j][0];
                this->policylayer_line_A[i][j][1] = Father->policylayer_line_A[i][j][1];
                this->policylayer_line_B[i][j][1] = Mother->policylayer_line_B[i][j][1];
                this->policylayer_line_A[i][j][2] = Father->policylayer_line_A[i][j][2];
                this->policylayer_line_B[i][j][2] = Mother->policylayer_line_B[i][j][2];
                this->policylayer_line_A[i][j][3] = Father->policylayer_line_A[i][j][3];
                this->policylayer_line_B[i][j][3] = Mother->policylayer_line_B[i][j][3];
                this->policylayer_line_A[i][j][4] = Father->policylayer_line_A[i][j][4];
                this->policylayer_line_B[i][j][4] = Mother->policylayer_line_B[i][j][4];
                this->policylayer_line_A[i][j][5] = Father->policylayer_line_A[i][j][5];
                this->policylayer_line_B[i][j][5] = Mother->policylayer_line_B[i][j][5];
            }
        }
    }
    void AImesh::predict(){
        double maxvalue;
        X=0;
        Y=0;
        for(this->i = 0;this->i < 19;this->i++){
            for(this->j = 0;this->j < 18;this->j++){
                if(this->input[i][j] != 0){
                    this->policylayer[i][j] =2*this->playernum;
                }
            }
        }
        if(playernum == 1){
            maxvalue = policylayer[0][0];
            for(this->i = 0;this->i < 19;this->i++){
                for(this->j = 0;this->j < 19;this->j++){
                    if((maxvalue > this->policylayer[i][j])&&(this->input[i][j] == 0)){
                        this->X = i;
                        this->Y = j;
                        maxvalue = this->policylayer[i][j];

                    }
                }
            }
        }else if(playernum == -1){
            maxvalue = policylayer[0][0];
            for(this->i = 0;this->i < 19;this->i++){
                for(this->j = 0;this->j < 19;this->j++){
                    if((maxvalue < this->policylayer[i][j])&&(this->input[i][j] == 0)){
                        this->X = i;
                        this->Y = j;
                        maxvalue = this->policylayer[i][j];
                    }
                }
            }
        }

    }
    void AImesh::mutate(){
        int a;
        double b;
        srand(time(NULL));
        for(this->i = 0;this->i<19;this->i++){
            for(this->j = 0;this->j<19;this->j++){
                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_tres_A[i][j] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][0] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][1] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][2] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][3] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][4] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_A[i][j][5] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;


                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_tres_B[i][j] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][0] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][1] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][2] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][3] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][4] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_tres_B[i][j][5] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;



            }
        }

        for(this->i = 0;this->i<361;this->i++){
            for(this->j = 0;this->j<361;this->j++){
                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_line_A[i][j] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][0] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][1] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][2] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][3] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][4] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_A[i][j][5] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;


                a = rand() - 16384;
                b = (double)a;
                this->hiddenlayer_line_B[i][j] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][0] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][1] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][2] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][3] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][4] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;
                a = rand() - 16384;
                b = (double)a;
                this->policylayer_line_B[i][j][5] += tanh(b/16384)*tanh(b/16384)*tanh(b/16384)/16;


            }
        }
    }

class game{
public:
    game();
    virtual ~game();
    void link(AImesh* a1,AImesh* a2,panel* d);
    void play();
    int winner,stonenum;
    AImesh* Player1;
    AImesh* Player2;
    panel* p;

};

game::game(){
    }
    game::~game(){
    }
    void game::link(AImesh* a1,AImesh* a2,panel* d){
        this->Player1 = a1;
        this->Player2 = a2;
        this->p = d;
        this->Player1->playernum = 1;
        this->Player2->playernum = -1;

    }
    void game::play(){
        this->stonenum = 0;
        this->winner = 0;
        p->clearSpace();
        p->firstStone();
        stonenum++;
        while(winner == 0){
            Player2->trans_from(p);
            Player2->calculate();
            Player2->predict();
            p->putPlayer2(Player2->X-9,Player2->Y-9);
            winner = p->whowin();
            stonenum++;
            if(stonenum > 140){
                winner = 3;
                continue;
            }
            if(winner == 2){
                continue;
            }
            Player1->trans_from(p);
            Player1->calculate();
            Player1->predict();
            p->putPlayer1(Player1->X-9,Player1->Y-9);
            winner = p->whowin();
            stonenum++;
            if(stonenum > 140){
                winner = 3;
                continue;
            }
        }

    }

int main()
{
    int gamenum,wind,indigo,mostwin;
    int winnum[4];
    panel p1 = panel();
    game g1 = game();
    AImesh a1 = AImesh();
    AImesh a2 = AImesh();
    AImesh a3 = AImesh();
    AImesh a4 = AImesh();
    a1.initalRandom();
    cin >> gamenum;
    for(indigo = 0;indigo < gamenum;indigo++){
    winnum[0] = 0;
    winnum[1] = 0;
    winnum[2] = 0;
    winnum[3] = 0;
    a2.geneInherit(&a1,&a1);
    a3.geneInherit(&a1,&a1);
    a4.geneInherit(&a1,&a1);
    a2.mutate();
    a3.mutate();
    a4.mutate();
    g1.link(&a1,&a2,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[1]++;
    }else{
        winnum[0]++;
    }
    g1.link(&a1,&a3,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[2]++;
    }else{
        winnum[0]++;
    }
    g1.link(&a1,&a4,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[3]++;
    }else{
        winnum[0]++;
    }
    g1.link(&a2,&a3,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[2]++;
    }else{
        winnum[1]++;
    }
    g1.link(&a2,&a4,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[3]++;
    }else{
        winnum[1]++;
    }
    g1.link(&a3,&a4,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[3]++;
    }else{
        winnum[2]++;
    }
    g1.link(&a2,&a1,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[0]++;
    }else{
        winnum[1]++;
    }
    g1.link(&a3,&a1,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[0]++;
    }else{
        winnum[2]++;
    }
    g1.link(&a4,&a1,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[0]++;
    }else{
        winnum[3]++;
    }
    g1.link(&a3,&a2,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[1]++;
    }else{
        winnum[2]++;
    }
    g1.link(&a4,&a2,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[1]++;
    }else{
        winnum[3]++;
    }
    g1.link(&a4,&a3,&p1);
    g1.play();
    p1.showpanel();
    cout << g1.winner<<endl;
    wind = g1.winner;
    if(wind == 2){
        winnum[2]++;
    }else{
        winnum[3]++;
    }
    mostwin = 0;
    if(winnum[0] < winnum[1]){
        mostwin = 1;
    }
    if(winnum[mostwin] < winnum[2]){
        mostwin = 2;
    }
    if(winnum[mostwin] < winnum[3]){
        mostwin = 3;
    }
    if(mostwin == 1){
        a1.geneInherit(&a2,&a2);
    }else if(mostwin == 2){
        a1.geneInherit(&a3,&a3);
    }else if(mostwin == 3){
        a1.geneInherit(&a4,&a4);
    }
    }
    return 0;
}
