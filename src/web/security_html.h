#ifndef SECURITY_HTML_H
#define SECURITY_HTML_H

#include <Arduino.h>

const char SECURITY_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover">
    <title>SECURITY CENTER</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700;900&family=Rajdhani:wght@300;400;600;700&display=swap');
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        html {
            overflow-x: hidden;
            -webkit-overflow-scrolling: touch;
        }
        body {
            font-family: 'Rajdhani', 'Courier New', 'Consolas', 'Monaco', monospace;
            background: #0a0a0a;
            background-image: 
                linear-gradient(0deg, transparent 24%, rgba(255,215,0,0.05) 25%, rgba(255,215,0,0.05) 26%, transparent 27%, transparent 74%, rgba(255,215,0,0.05) 75%, rgba(255,215,0,0.05) 76%, transparent 77%, transparent),
                linear-gradient(90deg, transparent 24%, rgba(255,215,0,0.05) 25%, rgba(255,215,0,0.05) 26%, transparent 27%, transparent 74%, rgba(255,215,0,0.05) 75%, rgba(255,215,0,0.05) 76%, transparent 77%, transparent);
            background-size: 50px 50px;
            color: #ffd700;
            line-height: 1.6;
            min-height: 100vh;
            min-height: 100dvh;
            padding: max(10px, env(safe-area-inset-top, 0px)) max(10px, env(safe-area-inset-right, 0px)) max(16px, env(safe-area-inset-bottom, 0px)) max(10px, env(safe-area-inset-left, 0px));
            position: relative;
            overflow-x: hidden;
            overflow-y: auto;
            -webkit-overflow-scrolling: touch;
        }
        body::before {
            content: '';
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(180deg, rgba(255,215,0,0.1) 0%, transparent 50%, rgba(255,0,0,0.1) 100%);
            pointer-events: none;
            z-index: 0;
        }
        .container {
            max-width: 900px;
            margin: 0 auto;
            position: relative;
            z-index: 1;
        }
        .header {
            text-align: center;
            margin-bottom: 30px;
            padding: 20px;
            border: 3px solid #ffd700;
            background: rgba(255,215,0,0.1);
            box-shadow: 
                0 0 20px rgba(255,215,0,0.3),
                inset 0 0 20px rgba(255,215,0,0.1);
        }
        h1 {
            font-family: 'Orbitron', monospace;
            font-size: 28px;
            font-weight: 900;
            color: #ffd700;
            text-transform: uppercase;
            letter-spacing: 3px;
            text-shadow: 
                0 0 10px rgba(255,215,0,0.8),
                0 0 20px rgba(255,215,0,0.6);
            margin-bottom: 10px;
        }
        .subtitle {
            font-size: 12px;
            color: rgba(255,215,0,0.7);
            letter-spacing: 2px;
            text-transform: uppercase;
        }
        .vault-status {
            text-align: center;
            padding: 15px;
            margin-bottom: 20px;
            border: 2px solid #ffd700;
            background: rgba(0,0,0,0.5);
            font-family: 'Orbitron', monospace;
            font-size: 14px;
            color: #ffd700;
            text-transform: uppercase;
            letter-spacing: 2px;
        }
        .vault-status.secure {
            border-color: #00ff00;
            color: #00ff00;
            box-shadow: 0 0 20px rgba(0,255,0,0.3);
        }
        .vault-status.breach {
            border-color: #ff0000;
            color: #ff0000;
            box-shadow: 0 0 30px rgba(255,0,0,0.5);
            animation: alert 1s ease-in-out infinite;
        }
        @keyframes alert {
            0%, 100% { opacity: 1; }
            50% { opacity: 0.7; }
        }
        .back-link {
            display: inline-block;
            padding: 10px 20px;
            margin-bottom: 20px;
            background: rgba(255,215,0,0.1);
            border: 2px solid #ffd700;
            color: #ffd700;
            text-decoration: none;
            text-transform: uppercase;
            letter-spacing: 2px;
            font-weight: 600;
            transition: all 0.3s;
        }
        .back-link:hover {
            background: rgba(255,215,0,0.2);
            box-shadow: 0 0 20px rgba(255,215,0,0.5);
        }
        .menu-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 30px;
            margin-top: 40px;
        }
        .menu-square {
            aspect-ratio: 1;
            background: rgba(255,215,0,0.05);
            border: 3px solid #ffd700;
            border-radius: 0;
            cursor: pointer;
            transition: all 0.3s;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            padding: 30px;
            text-decoration: none;
            color: #ffd700;
            position: relative;
            overflow: hidden;
            box-shadow: 
                0 0 20px rgba(255,215,0,0.3),
                inset 0 0 20px rgba(255,215,0,0.1);
        }
        .menu-square::before {
            content: '';
            position: absolute;
            top: -50%;
            left: -50%;
            width: 200%;
            height: 200%;
            background: linear-gradient(45deg, transparent, rgba(255,215,0,0.1), transparent);
            transform: rotate(45deg);
            transition: all 0.5s;
        }
        .menu-square:hover {
            border-color: #ffff00;
            box-shadow: 
                0 0 30px rgba(255,255,0,0.6),
                0 0 50px rgba(255,255,0,0.4),
                inset 0 0 30px rgba(255,255,0,0.2);
            transform: translateY(-5px) scale(1.02);
        }
        .menu-square:hover::before {
            animation: shine 1s ease-in-out;
        }
        @keyframes shine {
            0% { transform: translateX(-100%) translateY(-100%) rotate(45deg); }
            100% { transform: translateX(100%) translateY(100%) rotate(45deg); }
        }
        .menu-square.touch {
            border-color: #00ff00;
        }
        .menu-square.touch:hover {
            border-color: #00ff00;
            box-shadow: 
                0 0 40px rgba(0,255,0,0.8),
                0 0 60px rgba(0,255,0,0.6),
                inset 0 0 30px rgba(0,255,0,0.3);
        }
        .menu-square.vibration {
            border-color: #ff0000;
        }
        .menu-square.vibration:hover {
            border-color: #ff0000;
            box-shadow: 
                0 0 40px rgba(255,0,0,0.8),
                0 0 60px rgba(255,0,0,0.6),
                inset 0 0 30px rgba(255,0,0,0.3);
        }
        .menu-icon {
            font-size: 64px;
            margin-bottom: 20px;
            font-family: 'Orbitron', monospace;
            font-weight: 900;
            text-shadow: 0 0 20px currentColor;
        }
        .menu-title {
            font-family: 'Orbitron', monospace;
            font-size: 24px;
            font-weight: 700;
            text-transform: uppercase;
            letter-spacing: 3px;
            margin-bottom: 10px;
            color: inherit;
        }
        .menu-description {
            font-size: 14px;
            color: rgba(255,255,255,0.7);
            line-height: 1.5;
            text-align: center;
        }
        .menu-square.touch .menu-icon {
            color: #00ff00;
        }
        .menu-square.vibration .menu-icon {
            color: #ff0000;
        }
        @media (max-width: 600px) {
            .menu-grid {
                grid-template-columns: 1fr;
                gap: 20px;
            }
            .menu-square {
                padding: 20px;
            }
            .menu-icon {
                font-size: 48px;
            }
            .menu-title {
                font-size: 20px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>SECURITY CENTER</h1>
            <p class="subtitle">BANK VAULT MONITORING SYSTEM</p>
        </div>
        
        <div class="vault-status secure" id="vault-status">
            <span>🔒 VAULT STATUS: SECURE</span>
        </div>
        
        <a href="/" class="back-link">← BACK TO MENU</a>
        
        <div class="menu-grid">
            <a href="/security/door" class="menu-square touch">
                <div class="menu-icon">🚪</div>
                <div class="menu-title">Door Sensor</div>
                <div class="menu-description">Vault door status monitoring<br>Open/Closed detection</div>
            </a>
            
            <a href="/security/vibration" class="menu-square vibration">
                <div class="menu-icon">⚠️</div>
                <div class="menu-title">Intrusion Detection</div>
                <div class="menu-description">Vibration monitoring<br>Break-in attempt alerts</div>
            </a>
        </div>
    </div>
    
    <script>
        // Update vault status based on sensor readings
        async function updateVaultStatus() {
            try {
                const [doorRes, vibRes] = await Promise.all([
                    fetch('/security/api/door'),
                    fetch('/security/api/vibration')
                ]);
                
                const doorData = await doorRes.json();
                const vibData = await vibRes.json();
                
                const statusEl = document.getElementById('vault-status');
                
                if (vibData.alert || (vibData.detected && vibData.level > 50)) {
                    statusEl.className = 'vault-status breach';
                    statusEl.innerHTML = '<span>🚨 VAULT STATUS: BREACH DETECTED</span>';
                } else if (doorData.doorOpen) {
                    statusEl.className = 'vault-status secure';
                    statusEl.innerHTML = '<span>🚪 VAULT STATUS: DOOR OPEN</span>';
                } else {
                    statusEl.className = 'vault-status secure';
                    statusEl.innerHTML = '<span>🔒 VAULT STATUS: SECURE</span>';
                }
            } catch (error) {
                console.error('Error updating vault status:', error);
            }
        }
        
        // Update every 2 seconds
        updateVaultStatus();
        setInterval(updateVaultStatus, 2000);
    </script>
</body>
</html>
)rawliteral";

#endif
