#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		auto userIcon = cocos2d::CCSprite::create("gdzoltex.nothing/button-image.png");
		auto buttonSprite = ButtonSprite::create("My Button");

		auto myButton = CCMenuItemSpriteExtra::create(
			buttonSprite,
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		if (menu) {
			menu->addChild(myButton);
			myButton->setID("my-button"_spr);
			menu->updateLayout();
		}

		return true;
	}

	void onMyButton(CCObject*) {
		auto alert = FLAlertLayer::create(nullptr, "Nothing Mod v1", "\nwhy do you even click here?\n\n", "my bad", nullptr, 500.0f, false, 450.0f, 1.25f);
		if (!alert) return;

		auto bGit = ButtonSprite::create("GitHub");
		auto bKofi = ButtonSprite::create("Ko-Fi");
		auto bDisc = ButtonSprite::create("Discord");

		auto miGit = CCMenuItemSpriteExtra::create(bGit, this, menu_selector(MyMenuLayer::onLinkGitHub));
		auto miKofi = CCMenuItemSpriteExtra::create(bKofi, this, menu_selector(MyMenuLayer::onLinkKofi));
		auto miDisc = CCMenuItemSpriteExtra::create(bDisc, this, menu_selector(MyMenuLayer::onLinkDiscord));

		if (alert->m_buttonMenu) {
			alert->m_buttonMenu->addChild(miGit);
			alert->m_buttonMenu->addChild(miKofi);
			alert->m_buttonMenu->addChild(miDisc);
			alert->m_buttonMenu->alignItemsHorizontallyWithPadding(8.0f);
			cocos2d::CCSize alertSize = alert->getContentSize();
			alert->m_buttonMenu->setPosition(cocos2d::CCPoint(alertSize.width * 0.5f, alert->m_buttonMenu->getPositionY() + 6.0f));
		}

		alert->show();
	}

	void onLinkGitHub(CCObject*) { geode::utils::web::openLinkInBrowser("https://github.com/zoltex999"); }
	void onLinkKofi(CCObject*) { geode::utils::web::openLinkInBrowser("https://ko-fi.com/zoltex"); }
	void onLinkDiscord(CCObject*) { geode::utils::web::openLinkInBrowser("https://discord.gg/D9TCNr3VzE"); }
};
