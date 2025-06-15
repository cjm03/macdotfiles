-- player.lua
local map = require("map")
local player = {}

function player.load()
    player.x = 400
    player.y = 300
    player.speed = 200
    player.angle = 0
    player.dead = false
end

function player.update(dt)
    if player.dead then return end
    local dx, dy = 0, 0
    -- if love.keyboard.isScancodeDown("w") then dy = dy - 1 end
    -- if love.keyboard.isScancodeDown("s") then dy = dy + 1 end
    -- if love.keyboard.isScancodeDown("a") then dx = dx - 1 end
    -- if love.keyboard.isScancodeDown("d") then dx = dx + 1 end

    local newX = player.x
    local newY = player.y
    if love.keyboard.isScancodeDown("w") then newY = newY - player.speed * dt end
    if love.keyboard.isScancodeDown("s") then newY = newY + player.speed * dt end
    if love.keyboard.isScancodeDown("a") then newX = newX - player.speed * dt end
    if love.keyboard.isScancodeDown("d") then newX = newX + player.speed * dt end

    if not map.isBlocked(newX, player.y) then
        player.x = newX
    end
    if not map.isBlocked(player.x, newY) then
        player.y = newY
    end

    local len = math.sqrt(dx * dx + dy * dy)
    if len > 0 then
        dx, dy = dx / len, dy / len
        player.x = player.x + dx * player.speed * dt
        player.y = player.y + dy * player.speed * dt
    end

    local mx, my = love.mouse.getPosition()
    player.angle = math.atan2(my - player.y, mx - player.x)
end

function player.draw()
    if player.dead then
        love.graphics.setColor(1, 0, 0)
    else
        love.graphics.setColor(0, 1, 0)
    end
    love.graphics.push()
    love.graphics.translate(player.x, player.y)
    love.graphics.rotate(player.angle)
    love.graphics.rectangle("fill", -10, -10, 20, 20)
    love.graphics.pop()
    love.graphics.setColor(1, 1, 1)
end

return player
