#include<iostream>
#include<string>
#include<random>

using namespace std;

int main()
{
	mt19937 randGenerator(time(0));	// random number generator
	uniform_int_distribution<int> humanPower(50,100);		// damage caused by human
	uniform_int_distribution<int> robotPower(30,60);		// damage caused by robot

	// chance of hitting opponent
	uniform_real_distribution<float> chance(0.0f, 1.0f);	
	
	int num_humans, num_robots;
	char current_chance = 'H';		// The game starts with humans attacking
	
	// Human properties
	float human_attack = 0.60;
	int human_strength = 200;
	int human_damage = humanPower(randGenerator);		// Amount of damage done is random

	// Robot properties
	float robot_attack = 0.45;
	int robot_strength = 90;
	int robot_damage = robotPower(randGenerator);		// Amount of damage done is random

	int current_human = human_strength, current_robot = robot_strength;		// Tells the power of the current player fighting
			
	cout<<"Robots vs Humans!!!\n\n";
	cout<<"This is the game of robots vs humans, where \nthe two species battle it out to be the best on Planet Earth.\n\n";
	cout<<"Enter the number of humans you want to fight with"<<endl;
	cin>>num_humans;
	cout<<"Enter the number of robots"<<endl;
	cin>>num_robots;
	cout<<"\nStart fight!\n"<<endl;
	int temp_humans = num_humans, temp_robots = num_robots;
	while(temp_humans > 0 && temp_robots > 0)
	{
		float attack = chance(randGenerator);
		if (current_chance == 'H' && attack>human_attack)
		{
			current_robot -= human_damage;
			if (current_robot<0)
			{
				temp_robots--;
				current_robot = robot_strength;
			}
			current_chance = 'R';
		}
		else if(current_chance == 'R' && attack>robot_attack)
		{
			current_human -= robot_damage;
			if (current_human<0)
			{
				temp_humans--;
				current_human = human_strength;
			}
			current_chance = 'H';
		}
	}
	cout<<"FIGHT ENDED!!\n\nRESULTS --->\n\n";
	if(temp_robots == 0 && temp_humans>0)
	{
		cout<<"\tHUMANS WON!";
		cout<<"\n\tNumber of humans left = "<<temp_humans<<endl;
	}
	else if(temp_humans == 0 && temp_robots>0)
	{
		cout<<"\tROBOTS WON!";
		cout<<"\n\tNumber of robots left = "<<temp_robots<<endl;
	}
	else if(temp_robots == 0 && temp_humans == 0)
	{
		cout<<"\tTIE!";
	}
	cout<<"\tNumber of humans died = "<<num_humans-temp_humans<<", Number of robots died "<<num_robots-temp_robots<<endl;

	return 0;
}

