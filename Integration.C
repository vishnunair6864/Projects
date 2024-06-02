{

const int n=10;

float pi=TMath::Pi();
float a = 0;
float b = 2*pi;
float step=(b-a)/(n-1);
float dx[n];
float x[n];
float w[n];
float Int=0;


for(int i=0;i<n-1;i++)
{
w[i]=step;
dx[i]=f->Eval(x[i]);
Int=Int+dx[i]*w[i];
    cout<<endl;
}


for(int i=0;i<n;i++)
{
    {if(i==0||i==n-1) w[i]= 0.5*step;
    else w[i]=step;
         }
dx[i]=f->Eval(x[i]);
Int=Int+dx[i]*w[i];
    cout<<endl;
}
int even = 0;
int odd = 0;


for(int i=0;i<n/2;i++)
{
even=2*i;
odd=2*i+1;
w[even]=4.0/3;
w[odd]=2.0/3;
dx[i]=f->Eval(x[i]);
Int=Int+dx[i]*w[i];
w[0]=1/3;
w[n-1]=1/3;
    cout<<endl;
}



TCanvas*c1=new TCanvas("c1","Mid-Point",500,500);
c1->cd();

f=new TF1("f","cos(x)",0,pi/2);
g=new TF1("g","cos(x)",0,pi);

g->SetLineColor(8);
g->Draw();
 
f->SetLineColor(9);
f->Draw();


for(int i=0;i<n;i++)
{
b1=new TBox(x[i],0,dx[i],x[i]+(dx[i]/2));
b1->Draw();
}



TCanvas*c2=new TCanvas("c2","Trapezoid",500,500);
c2->cd();

f=new TF1("f","cos(x)",0,pi/2);
g=new TF1("g","cos(x)",0,pi);

g->SetLineColor(8);
g->Draw();
 
f->SetLineColor(9);
f->Draw();

for(int i=0;i<n;i++)
{
l2=new TLine(x[i],0,dx[i],x[i]+(dx[i]/2));
l2->Draw();
}


TCanvas*c3=new TCanvas("c3","Simpson",500,500);
c3->Divide();
c3->cd();
f=new TF1("f","cos(x)",0,pi/2);
g=new TF1("g","cos(x)",0,pi);

g->SetLineColor(8);
g->Draw();
 
f->SetLineColor(9);
f->Draw();

}