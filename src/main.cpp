#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace geode::prelude;

class $modify(MenuLayerSwap, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = this->getChildByID("main-menu");
        if (!menu) return true;

        auto play = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("play-button"));
        auto editor = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("editor-button"));

        auto garage = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("garage-button"));

        if (play && editor) {
            auto pPos = play->getPosition();
            auto ePos = editor->getPosition();

            play->setPosition(ePos);
            editor->setPosition(pPos);
            play->setScale(0.65f);
            editor->setScale(1.45f);
        } else {
            log::error("error while swapping buttons  >:(");
        }

        if (garage) {
            garage->setScale(0.65f);
        }

        return true;
    }
};
