-- main.lua
local map = require("map")
local player = require("player")
local bullet = require("bullet")
local enemy = require("enemy")
local enemyRespawnTimer = 0
local enemyRespawnDelay = 2

function love.load()
    love.window.setMode(1280, 960)
    player.load()
    enemy.load()
    map.load()
end

function love.update(dt)
    player.update(dt)
    bullet.update(dt)
    enemy.update(dt, player.x, player.y)

    -- Check player death
    if enemy.canSeePlayer and enemy.alive then
        player.dead = true
    end

    -- Check bullet-enemy collision
    for i, b in ipairs(bullet.list) do
        if enemy.alive and bullet.checkCollision(b, enemy) then
            enemy.alive = false
        end
    end
    
    -- Handle enemy death and respawn
    if not enemy.alive then
        enemyRespawnTimer = enemyRespawnTimer + dt
        if enemyRespawnTimer >= enemyRespawnDelay then
            enemy.load()
            enemyRespawnTimer = 0
        end
    end
end

function love.draw()
    map.draw()
    player.draw()
    bullet.draw()
    enemy.draw()
end

function love.mousepressed(x, y, button)
    if button == 1 and not player.dead then
        bullet.shoot(player.x, player.y, player.angle)
    end
end

function love.keypressed(key)
    if key == "r" then
        love.load()
    end
end

