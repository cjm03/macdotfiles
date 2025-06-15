-- bullet.lua
local map = require("map")
local bullet = {}
bullet.list = {}
local bulletCount = 0

function bullet.shoot(x, y, angle)
    if bulletCount > 4 then
        table.remove(bullet.list, 1)
        bulletCount = bulletCount - 1
    end
    table.insert(bullet.list, {
        x = x,
        y = y,
        dx = math.cos(angle),
        dy = math.sin(angle),
        speed = 500
    })
    bulletCount = bulletCount + 1
end

function bullet.update(dt)
    for i = #bullet.list, 1, -1 do
        local b = bullet.list[i]
        local nextX = b.x + b.dx * b.speed * dt
        local nextY = b.y + b.dy * b.speed * dt

        if map.isBlocked(nextX, nextY) then
            if map.isBlocked(nextX, b.y) then
                b.dx = -b.dx
            end
            if map.isBlocked(b.x, nextY) then
                b.dy = -b.dy
            end
        else
            b.x = nextX
            b.y = nextY
        end
        -- b.x = b.x + math.cos(b.angle) * b.speed * dt
        -- b.y = b.y + math.sin(b.angle) * b.speed * dt
        --
        -- if b.x < 0 or b.y < 0 or b.x > 1280 or b.y > 960 then
        --     table.remove(bullet.list, i)
        -- end
    end
end

function bullet.draw()
    for _, b in ipairs(bullet.list) do
        love.graphics.circle("fill", b.x, b.y, 4)
    end
end

function bullet.checkCollision(b, enemy)
    local dist = math.sqrt((b.x - enemy.x)^2 + (b.y - enemy.y)^2)
    return dist < 15
end

return bullet
