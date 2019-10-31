#include<iostream>
#include<algorithm>
using namespace std;

//int main(){
//    printf("hello world!\n");
//}
/*
//my code
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int *L = new int[k];
		int *R = new int[k];
		for (int j = 0; j < k; j++)
		{
			cin >> L[j] >> R[j];
		}
		int count = 0;
		int location = 0;
		int lastL = L[0];
		int lastR = R[0];
		int q = 0;
		for (q = 1; q < k; q++)
		{
			//cout << "NO:" << q <<" "<<lastL<<" "<<lastR<<endl;
			if (lastL <= L[q]&&R[q] <= lastR)
			{
				lastL = L[q];
				lastR = R[q];
			}
			else if (lastL >= L[q]&&R[q] >= lastR)
			{
				;
			}
			else if (lastL <= L[q]&&R[q] >= lastR&&L[q]<lastR)//a bug
			{
				lastL = L[q];

			}
			else if (lastL >= L[q]&&R[q] <= lastR&&R[q]>lastL)//a bug
			{
				lastR = R[q];
			}
			else
			{
				break;
			}
		}
		if (L[q] > lastR)
		{
			count += (L[q] - lastR) / 2;
			if ((L[q]-lastR)%2==0)
			{
				
				location = L[q];
			}
			else
			{
				count++;
				int temp = q + 1;
				while (L[temp]<=L[q]&&R[temp]>=L[q]+1)
				{
					temp++;
				}
				if (L[temp]>=L[q]+1)
				{
					location = L[q] + 1;
				}
				else
				{
					location = L[q];
				}
			}
		}
		if (R[q] < lastL)
		{
			count += (lastL - R[q]) / 2;
			if ((lastL - R[q]) % 2==0)
			{
				location = R[q];
			}
			else
			{
				count++;
				int temp = q + 1;
				while (L[temp] <= R[q]-1 && R[temp] >= R[q])
				{
					temp++;
				}
				if (R[temp] <= R[q] - 1)
				{
					location = R[q] - 1;
				}
				else
				{
					location = R[q];
				}
			}

		}

		for (q=q+1; q<k; q++)
		{
			if (L[q]>location)
			{
				lastR = location;
				count += (L[q] - lastR) / 2;
				if ((L[q] - lastR) % 2 == 0)
				{

					location = L[q];
				}
				else
				{
					count++;
					int temp = q + 1;
					while (L[temp] <= L[q] && R[temp] >= L[q] + 1)
					{
						temp++;
					}
					if (L[temp] >= L[q] + 1)
					{
						location = L[q] + 1;
					}
					else
					{
						location = L[q];
					}
				}
			}
			if (R[q]<location)
			{
				lastL = location;
				count += (lastL - R[q]) / 2;
				if ((lastL - R[q]) % 2 == 0)
				{
					location = R[q];
				}
				else
				{
					count++;
					int temp = q + 1;
					while (L[temp] <= R[q] - 1 && R[temp] >= R[q])
					{
						temp++;
					}
					if (R[temp] <= R[q] - 1)
					{
						location = R[q] - 1;
					}
					else
					{
						location = R[q];
					}
				}
			}
			//cout << "NO:" << q << " " << count << endl;
		}


		
		cout << count << endl;
	}
	
	return 0;
}
*/
//reference: https://blog.csdn.net/qq_41505957/article/details/99701167
#define N 1020
using namespace std;
int a[N], b[N];
int main() {
    int t, n, l, r, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%d%d", &a ,&b);
        
        for(i=1; i<n; i++)
            scanf("%d%d", &a[i], &b[i]);
        l=a[0];r=b[0];
        for(i=1; i<n; i++) {                        //选相交区间
            if(max(l, a[i])>min(r, b[i]))
                break;
            l=max(l, a[i]);
            r=min(r, b[i]);
        }
        if(i==n)                                  //所有任务完成，结束
        {
            printf("0\n");
            continue;
        }
        int ans=0, sum;
        
        if(b[i]<l) 
            sum=l;  
        else sum=r;
        int temp=0;
  
        for(; i<n-1; i++)                     //没有考虑最后一个，因为要用到 i+1 项任务
        {
            if(sum>b[i]) {
                if (temp==-1)                 //步数可以移动
                    sum--;
                ans+=(sum-b[i]+1)/2;           //更新步数
                if((sum-b[i])%2==1 && b[i]-a[i]>=1)      //判断区间只有一个点的情况
                    temp=-1;                       //更新可以移动的步数
                else temp=0;      
                sum=b[i];                        //更新位置
            }
            else if(sum < a[i]) {
                if (temp==1)
                    sum++;
                ans+=(a[i]-sum+1)/2;
 
                if((a[i]-sum)%2==1 && b[i]-a[i]>=1)
                    temp=1;
                else temp=0;
                sum=a[i];
            }
            else {
                if (sum==a[i] && temp==-1)
                    temp=0;
                else if (sum==b[i] && temp==1)
                    temp=0;
            }
        }
        //printf("!%d %d %d\n", sum, ans, temp);
        if(sum>b[i]) {                    //考虑最后一个
            if (temp==-1)
                sum--;
            ans += (sum-b[i] + 1)/2;
        }
        else if(sum<a[i]) {
            if (temp==1)
                sum++;
            ans+=(a[i]-sum+1)/2;
        }
        
        printf("%d\n",ans);
    }
    return 0;
}

