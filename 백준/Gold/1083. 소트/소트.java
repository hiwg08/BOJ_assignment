import java.io.*;
import java.util.*;

public class Main
{
	static int N, S, MAX, MAX_index;
	static int[] arr = new int[51];
	static BufferedReader sc;
	static StringTokenizer st1;
	public static void main(String[] args) throws Exception
	{
		sc = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(sc.readLine());
		st1 = new StringTokenizer(sc.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st1.nextToken());
		S = Integer.parseInt(sc.readLine());
		Rec();
		for (int i = 0; i < N; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
			
	}
	private static void Rec()
	{
		for (int i = 0; i < N; i++)
		{
			MAX = arr[i];
			MAX_index = i;
			if (S == 0)
				break;
			for (int j = i + 1; j < i + 1 + S; j++)
			{
				if (j >= N)
					continue;
				if (MAX < arr[j])
				{
					MAX = arr[j];
					MAX_index = j;
				}
			}
			if (MAX_index == i)
				continue;
			while(true)
			{
				swap(MAX_index, MAX_index - 1);
				S--;
				if (--MAX_index == i)
					break;	
			}
		}
	}
	private static void swap(int q, int w)
	{
		int temp = arr[q];
		arr[q] = arr[w];
		arr[w] = temp;
	}
}