#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayerSwap, MenuLayer) {
    void applyButtonLayout() {
        auto* mainMenu = this->getChildByID("main-menu");
        if (!mainMenu) {
            return;
        }

        auto* playButton = typeinfo_cast<CCMenuItemSpriteExtra*>(mainMenu->getChildByID("play-button"));
        auto* editorButton = typeinfo_cast<CCMenuItemSpriteExtra*>(mainMenu->getChildByID("editor-button"));
        auto* garageButton = typeinfo_cast<CCMenuItemSpriteExtra*>(mainMenu->getChildByID("garage-button"));

        if (playButton && editorButton) {
            const auto playPosition = playButton->getPosition();
            const auto editorPosition = editorButton->getPosition();

            playButton->setPosition(editorPosition);
            editorButton->setPosition(playPosition);
            playButton->setScale(0.65f);
            editorButton->setScale(1.45f);
        } else {
            log::warn("swapping play and editor buttons failed >:(");
        }

        if (garageButton) {
            garageButton->setScale(0.65f);
        }
    }

    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        return true;
    }

    void onEnter() {
        MenuLayer::onEnter();
        this->applyButtonLayout();
    }
};
