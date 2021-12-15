#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
#include "windows.h"
#include "Shapes.h"

using namespace std;

int main() {

	//ask for number of shapes to render, just so I don't have to change the code everytime I want something different
	cout << "How many shapes do you want to render?" << endl;
	cin >> NumOfShapesToRender;
	if (NumOfShapesToRender == -1) {
		NumOfShapesToRender++;
		GraphFunction(0, 0, 200);
	}
	else{
		for (int i = 0; i < NumOfShapesToRender; i++) {
			//adjust order to have correct number of places
			order.push_back(0);
			//ask for type of each shape
			cout << "Type of shape " << i + 1 << "?" << endl;
			cout << "0 for point" << endl << "1 for line" << endl << "2 for surface" << endl;
			cin >> TypeTemp;
			//record class of shape in type
			type.push_back(TypeTemp);
			//ask for coordinates based on case, and adjust each vector to have the correct length
			if (TypeTemp == 0) {
				cout << "input x, y, and z" << endl;
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p1.push_back(CoordinateTemp);
				p2.push_back({ 0,0,0 });
				p3.push_back({ 0,0,0 });
			}
			else if (TypeTemp == 1) {
				cout << "input x1, y1, z1, x2, y2, and z2" << endl;
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p1.push_back(CoordinateTemp);
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p2.push_back(CoordinateTemp);
				p3.push_back({ 0,0,0 });
			}
			else {
				cout << "input x1, y1, z1, x2, y2, z2, x3, y3, and z3" << endl;
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p1.push_back(CoordinateTemp);
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p2.push_back(CoordinateTemp);
				for (int j = 0; j < 3; j++) {
					cin >> CoordinateTemp[j];
				}
				p3.push_back(CoordinateTemp);
			}
			//ask for color, make sure it works 
			cout << "What color? Input in RGB values" << endl;
			for (int j = 0; j < 3; j++) {
				cin >> CoordinateTemp[j];
			}
			coloruuuuuuu.push_back(CoordinateTemp);
		}
	}

	while (window.isOpen()) {
		//record start time
		t = clock();
		counter++;

		//clear window and get mousepos
		window.clear();
		mousePos = sf::Mouse::getPosition(window);

		//check for closing window
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		//receive input from keyboard
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				yes[1] = -scale;
			}
			if (event.key.code == sf::Keyboard::Down) {
				yes[1] = scale;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
				scale += 0.01;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
				scale -= 0.01;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				yes[0] = -scale;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				yes[0] = scale;
			}
		}
		else {
			for (int i = 0; i < yes.size(); i ++) {
				yes[i] = 0;
			}
		}

		//recieve input from mouse 
		//lol tbh idk how to write instructions on using this, just move ur mouse around and it'll make sense after like a few minutes
		if (abs(mousePos.x - WinSize / 2) > 200) {
			yr = (signbit((float)(mousePos.x - WinSize / 2)) * 2 - 1);
		}
		else {
			yr = 0;
		}

		if (abs(mousePos.y - WinSize / 2) > 200) {
			xr = (signbit((float)(mousePos.y - WinSize / 2)) * 2 - 1);
			zr = -(signbit((float)(mousePos.y - WinSize / 2)) * 2 - 1);
		}
		else {
			xr = 0;
			zr = 0;
		}

		//-------------------------

		//rotate the shapes
		for (int i = 0; i < type.size(); i++) {
			if (type[i] == 0) {
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * xr, 0);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * yr, 1);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * zr, 2);
			}
			else if (type[i] == 1) {
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * xr, 0);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * yr, 1);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * zr, 2);

				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * xr, 0);
				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * yr, 1);
				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * zr, 2);
			}
			else {
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * xr, 0);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * yr, 1);
				p1[i] = rotation(p1[i][0], p1[i][1], p1[i][2], rotationspeed * zr, 2);

				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * xr, 0);
				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * yr, 1);
				p2[i] = rotation(p2[i][0], p2[i][1], p2[i][2], rotationspeed * zr, 2);

				p3[i] = rotation(p3[i][0], p3[i][1], p3[i][2], rotationspeed * xr, 0);
				p3[i] = rotation(p3[i][0], p3[i][1], p3[i][2], rotationspeed * yr, 1);
				p3[i] = rotation(p3[i][0], p3[i][1], p3[i][2], rotationspeed * zr, 2);
			}
		}

		//translate each shape
		for (int i = 0; i < type.size(); i++) {
			if (type[i] == 0) {
				p1[i][0] += yes[0];
				p1[i][1] += yes[1];
				p1[i][2] += yes[2];
			}
			else if (type[i] == 1) {
				p1[i][0] += yes[0];
				p1[i][1] += yes[1];
				p1[i][2] += yes[2];

				p2[i][0] += yes[0];
				p2[i][1] += yes[1];
				p2[i][2] += yes[2];
			}
			else {
				p1[i][0] += yes[0];
				p1[i][1] += yes[1];
				p1[i][2] += yes[2];

				p2[i][0] += yes[0];
				p2[i][1] += yes[1];
				p2[i][2] += yes[2];

				p3[i][0] += yes[0];
				p3[i][1] += yes[1];
				p3[i][2] += yes[2];
			}
		}

		//order each shape
		organize();

		//render, color, and shade each shape
		for (int i = 0; i < type.size(); i++) {
			if (type[order[i]] == 0) {
				//treat the point as a circle of rad=5, set and draw it
				boll.setPosition(p1[order[i]][0] * scale + CenterOfScreen, p1[order[i]][1] * scale + CenterOfScreen);
				boll.setFillColor(sf::Color(coloruuuuuuu[order[i]][0], coloruuuuuuu[order[i]][1], coloruuuuuuu[order[i]][2]));
				window.draw(boll);
			}
			else if (type[order[i]] == 1) {
				//set line
				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(p1[order[i]][0] * scale + CenterOfScreen, p1[order[i]][1] * scale + CenterOfScreen), sf::Color(coloruuuuuuu[order[i]][0], coloruuuuuuu[order[i]][1], coloruuuuuuu[order[i]][2])),
					sf::Vertex(sf::Vector2f(p2[order[i]][0] * scale + CenterOfScreen, p2[order[i]][1] * scale + CenterOfScreen), sf::Color(coloruuuuuuu[order[i]][0], coloruuuuuuu[order[i]][1], coloruuuuuuu[order[i]][2]))
				};
				//draw line
				window.draw(line, 2, sf::Lines);
			}
			else {
				// resize it to 3 points
				kaiser.setPointCount(3);

				// define the points
				kaiser.setPoint(0, sf::Vector2f(p1[order[i]][0] * scale + CenterOfScreen, p1[order[i]][1] * scale + CenterOfScreen));
				kaiser.setPoint(1, sf::Vector2f(p2[order[i]][0] * scale + CenterOfScreen, p2[order[i]][1] * scale + CenterOfScreen));
				kaiser.setPoint(2, sf::Vector2f(p3[order[i]][0] * scale + CenterOfScreen, p3[order[i]][1] * scale + CenterOfScreen));

				//set color with shading
				shad = shading(p1[order[i]][0], p1[order[i]][1], p1[order[i]][2], p2[order[i]][0], p2[order[i]][1], p2[order[i]][2], p3[order[i]][0], p3[order[i]][1], p3[order[i]][2]);
				kaiser.setFillColor(sf::Color(shad * coloruuuuuuu[order[i]][0] + 25, shad * coloruuuuuuu[order[i]][1] + 25, shad * coloruuuuuuu[order[i]][2] + 25));

				window.draw(kaiser);
			}
		}

		//-------------------------

		//display 
		window.display();

		//record end time
		t = clock() - t;
		AvgT += ((float)t) / CLOCKS_PER_SEC;
		cout << "time elapsed: " << AvgT / counter << endl;
	}
	
	return 0;
}
