#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* g)
{
	game = g;

	//MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY));
	MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY), beginGame, game);
	MenuButton* cargar = new MenuButton({ 50,400 }, 150, 50, game->getArrayTex(EXIT), endGame, game);

	sceneObjects.push_back(jugar);
	sceneObjects.push_back(cargar);
}

MainMenuState::~MainMenuState()
{
	for (auto e : sceneObjects) {
		delete(e);
	}
}

void MainMenuState::update()
{
	for (auto it : sceneObjects) {
		it->update();
	}
}

void MainMenuState::render()
{
	for (auto it : sceneObjects) {
		it->render();
	}
}

void MainMenuState::handleEvent()
{	

	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_MOUSEBUTTONDOWN:
			switch (ev.button.button) {
			case SDL_BUTTON_LEFT:
				//std::cout << "click " << name << "\n";
				//checkBounds();
				for (auto it : sceneObjects) {
						auto objeto = dynamic_cast<MenuButton*>(it);
						objeto->handleEvent();
						if (objeto->getPressed()) {
							std::cout << "hola bitch \n";
							break;
						}
				}
				break;
			}
			break;
		}
	}
	//for (auto it : sceneObjects) {
	//	/*it->handleEvent();
	//	if (it->buttonPressed()) {
	//		std::cout << "hola bitch \n";
	//		break;
	//	}
	//	auto objeto = dynamic_cast<MenuButton*>(it);
	//	objeto->handleEvent();
	//	if (objeto->getPressed()) {
	//		std::cout << "hola bitch \n";
	//		break;
	//	}*/
	//	it->handleEvent();
	//}
	
}

bool MainMenuState::onEnter()
{
	std::cout << "entrando en MenuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	std::cout << "saliendo de MenuState\n";
	return true;
}

void MainMenuState::beginGame(Game* game)
{
	game->getStateMachine()->changeState(new PlayState(game));
	//std::cout << "hola";
}

void MainMenuState::endGame(Game* game)
{
	game->getStateMachine()->popState();
	game->setExit();
	//std::cout << "hola";
}

void MainMenuState::loadGame(Game* game)
{

	/*string nombre;
		cout << "\n";
		cin >> nombre;
		string aux = "../saveGames/save" + nombre + ".dat";
		fstream loadInput;
	
		loadInput.open(aux);
	
		if (!loadInput) throw FileNotFoundError(nombre + ".dat");
		loadInput >> currentLevel >> lives;
		
		blocksMap = new BlocksMap(loadInput, arrayTex[BRICKS], this);
		objectsList.push_back(blocksMap);
		walls[0] = new Wall(loadInput, arrayTex[SIDE]);
		objectsList.push_back(walls[0]);
		walls[1] = new Wall(loadInput, arrayTex[TOPSIDE]);
		objectsList.push_back(walls[1]);
		walls[2] = new Wall(loadInput, arrayTex[SIDE]);
		objectsList.push_back(walls[2]);
		player = new Paddle(loadInput, arrayTex[PADDLE], this);
		objectsList.push_back(player);
		ball = new Ball(loadInput, arrayTex[BALL], this);
		objectsList.push_back(ball);
			
		loadInput.close();*/
}
