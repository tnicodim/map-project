<a name="readme-top"></a>



[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/turtleterry/map-project">
    <img src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fcdn4.iconfinder.com%2Fdata%2Ficons%2Fdigital-marketing-7-1%2F128%2F325-512.png&f=1&nofb=1&ipt=39c80a0b53c861eb93a7a4bd6fa89e784010a9498777323eb87cd2e216d10aab&ipo=images" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">8 Rooks</h3>

  <p align="center">
    A C++ application showcasing the 8 rooks problem
    <br />
    <a href="https://github.com/turtleterry/map-project"><strong>Explore the repository »</strong></a>
    <br />
    <br />
    <a href="https://github.com/turtleterry/map-project/issues">Report Bug</a>
    ·
    <a href="https://github.com/turtleterry/map-project/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#running-the-program">Running the Program</a></li>
      </ul>
    </li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project


This project explores the 8 rook problem. The main goal was to familiarize myself with GitHub & DockerHub and start using them in all future projects. 

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* ![Docker]
* ![cpp]
* ![mvs]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To get a local container up and running follow these simple steps.

### Prerequisites

* [Docker Desktop](https://www.docker.com/products/docker-desktop/)

### Running the program

1. [Install](https://www.docker.com/products/docker-desktop/) and configure Docker Desktop
2. Open a terminal and run the following code
   ```sh
   docker run --rm -it turtleterry/chess8rooks
   ```
3. Enjoy!

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

After successfully downloading the docker image and running a container the program will present an empty chessboard and a menu. There the user can choose one of the 4 options.
 <p align="center"><img src="https://i.ibb.co/BZ9PM4H/Img1.jpg"></p>
 
#### 1. Add a new rook

The add a new rook option allows the user to input a square where he would like to place a rook. This function has a validation function which checks if the user has written a valid chess notation && if the square is not occupied/attacked by other rooks.

```cpp
int isValid(int x,int y) {
	if (board[x][y] != 0)
		return 0;
	return 1;
}
```

```cpp

			while (!ok) {
				cout << "Choose a square using standard chess notation (ex: a4, f7 etc.): ";
				cin >> position;
				x = 8 - (int)(position[1] - 48);
				y = position[0] - 97;
				if (!(x >= 0 && x <= 7) || !(y >= 0 && y <= 7))
					cout << "Invalid notation! Try again.\n";
				else
				{
					if (isValid(x, y))
						ok = 1;
					else
						cout << "\nInvalid placement!! Two rooks are attacking each other!\n\n";
				}
			}
			initBoard(x, y);
```

#### 2. Automatic rook placement

This option will automatically fill in all the remaining valid squares with rooks. The algorithm goes through the 8x8 matrix which represents each square of the board and places rooks on the first valid squares it finds.

```sh
void placeRooks(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == 0)
				initBoard(i, j);
}
```

#### 3. Restart board

Removes all rooks on the board and clears the rook matrix.

#### 4. Exit

Exits the program.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Tolico Nicodim - tnicodimt@gmail.com

Project Link: [https://github.com/turtleterry/map-project](https://github.com/turtleterry/map-project)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [README.md Template](https://github.com/othneildrew/Best-README-Template)
* [IMG Shields](https://shields.io/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/turtleterry/map-project.svg?style=for-the-badge
[contributors-url]: https://github.com/turtleterry/map-project/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/turtleterry/map-project.svg?style=for-the-badge
[forks-url]: https://github.com/turtleterry/map-project/network/members
[stars-shield]: https://img.shields.io/github/stars/turtleterry/map-project.svg?style=for-the-badge
[stars-url]: https://github.com/turtleterry/map-project/stargazers
[issues-shield]: https://img.shields.io/github/issues/turtleterry/map-project.svg?style=for-the-badge
[issues-url]: https://github.com/turtleterry/map-project/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/nicodim-tolico
[product-screenshot]: images/screenshot.png
[Docker]: https://img.shields.io/badge/Docker%20Hub-ffffff.svg?logo=docker&style=for-the-badge&logoColor=white&color=blue
[cpp]: https://img.shields.io/badge/-C++-365dbf.svg?logo=C%2B%2B&style=for-the-badge
[mvs]: https://img.shields.io/badge/-Visual%20Studio-5C2D91.svg?logo=visual-studio&style=for-the-badge
