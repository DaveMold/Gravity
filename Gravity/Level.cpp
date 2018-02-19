#include "Level.h"
#include "InputManager.h"

Level::Level(sf::RenderWindow &w)
	: tileSize_(25)
{
	int x = 5, y = 10;
	startLevelTime_ = startLevelTime_.Zero;
	player_ = new Player(tileSize_, 4, sf::Vector2f(x * tileSize_, y * tileSize_), Player::CIRCLE, sf::Vector2f(width_ * tileSize_, height_ * tileSize_));
	x += 5, y -= 1;
	platforms_.push_back(new Platform(tileSize_, tileSize_, 4, sf::Vector2f((x * tileSize_) - (tileSize_ ), y* tileSize_)));
}

float Level::GetLevelTime() {
	return levelTime_.asSeconds();
}

void Level::ResetLevelTime() {
	levelTime_ = startLevelTime_.Zero;
	startLevelTime_ = levelTime_;
}

sf::Vector2f Level::GetPlayerPos() {
	return player_->GetPos();
}

void Level::UpdateLevelTime(sf::Time totalTime) {
	//Record Level Time
	if (startLevelTime_ == startLevelTime_.Zero)
		startLevelTime_ = totalTime;
	levelTime_ = totalTime - startLevelTime_;
}


Level::~Level() {

}

void Level::clearLevel() {
	delete player_;

	for (int i = 0; i < platforms_.size(); i++)
	{
		delete platforms_[i];
	}
	
	platforms_.clear();
	map_.clear();
}

std::pair<bool, bool> Level::Update(sf::Vector2f g, sf::RenderWindow &w, sf::Time runTime) {
	sf::Vector2f collisonF;
	//Record Level time.
	UpdateLevelTime(runTime);
	//Player
	player_->Update(g);
	//Platforms
	for (auto itr = platforms_.begin(); itr != platforms_.end(); itr++)
	{
		(*itr)->Update();
	}


	
	return std::make_pair<bool, bool>(false, false);
}

bool Level::PlayerOffScreen(Player * p) {
	if (player_->IsOffScreen())
	{
		return true;
	}
	return false;
}

sf::View Level::getFollowCamView() {
	return player_->getView();
}

void Level::Draw(sf::RenderWindow &w) {
	for (auto itr = platforms_.begin(); itr != platforms_.end(); itr++)
	{
		(*itr)->Draw(w);
	}
	
	player_->Draw(w);

}
