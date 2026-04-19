#ifndef SECURITY_DASHBOARD_HTML_H
#define SECURITY_DASHBOARD_HTML_H

#include <Arduino.h>

const char SECURITY_DASHBOARD_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover">
    <title>SECURITY DASHBOARD</title>
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
        .dashboard {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-top: 20px;
        }
        .security-card {
            background: rgba(255,215,0,0.1);
            border: 3px solid #ffd700;
            padding: 30px;
            text-align: center;
            box-shadow: 
                0 0 20px rgba(255,215,0,0.3),
                inset 0 0 20px rgba(255,215,0,0.1);
            position: relative;
        }
        .security-card.touch {
            border-color: #00ff00;
            box-shadow: 
                0 0 20px rgba(0,255,0,0.3),
                inset 0 0 20px rgba(0,255,0,0.1);
        }
        .security-card.touch.authorized {
            border-color: #00ff00;
            box-shadow: 
                0 0 40px rgba(0,255,0,0.8),
                0 0 60px rgba(0,255,0,0.6),
                inset 0 0 30px rgba(0,255,0,0.3);
            animation: pulse-green 2s ease-in-out infinite;
        }
        @keyframes pulse-green {
            0%, 100% { box-shadow: 0 0 40px rgba(0,255,0,0.8), 0 0 60px rgba(0,255,0,0.6), inset 0 0 30px rgba(0,255,0,0.3); }
            50% { box-shadow: 0 0 60px rgba(0,255,0,1), 0 0 80px rgba(0,255,0,0.8), inset 0 0 40px rgba(0,255,0,0.5); }
        }
        .security-card.vibration {
            border-color: #ff0000;
            box-shadow: 
                0 0 20px rgba(255,0,0,0.3),
                inset 0 0 20px rgba(255,0,0,0.1);
        }
        .security-card.vibration.alert {
            border-color: #ff0000;
            box-shadow: 
                0 0 40px rgba(255,0,0,0.8),
                0 0 60px rgba(255,0,0,0.6),
                inset 0 0 30px rgba(255,0,0,0.3);
            animation: alert-red 1s ease-in-out infinite;
        }
        @keyframes alert-red {
            0%, 100% { opacity: 1; box-shadow: 0 0 40px rgba(255,0,0,0.8), 0 0 60px rgba(255,0,0,0.6), inset 0 0 30px rgba(255,0,0,0.3); }
            50% { opacity: 0.8; box-shadow: 0 0 60px rgba(255,0,0,1), 0 0 80px rgba(255,0,0,0.8), inset 0 0 40px rgba(255,0,0,0.5); }
        }
        .security-icon {
            font-size: 64px;
            margin-bottom: 15px;
        }
        .security-label {
            font-size: 14px;
            color: rgba(255,255,255,0.7);
            text-transform: uppercase;
            letter-spacing: 2px;
            margin-bottom: 15px;
        }
        .security-status {
            font-family: 'Orbitron', monospace;
            font-size: 32px;
            font-weight: 700;
            color: #ffd700;
            text-shadow: 0 0 15px rgba(255,215,0,0.8);
            margin-bottom: 10px;
            text-transform: uppercase;
        }
        .security-card.touch .security-status {
            color: #00ff00;
            text-shadow: 0 0 15px rgba(0,255,0,0.8);
        }
        .security-card.touch.authorized .security-status {
            color: #00ff00;
            text-shadow: 0 0 20px rgba(0,255,0,1);
        }
        .security-card.vibration .security-status {
            color: #ff0000;
            text-shadow: 0 0 15px rgba(255,0,0,0.8);
        }
        .security-value {
            font-family: 'Orbitron', monospace;
            font-size: 24px;
            color: rgba(255,255,255,0.6);
            margin-top: 10px;
        }
        .security-description {
            margin-top: 20px;
            padding: 15px;
            background: rgba(0,0,0,0.3);
            border: 1px solid currentColor;
            font-size: 12px;
            color: rgba(255,255,255,0.7);
            line-height: 1.6;
        }
        .update-info {
            text-align: center;
            margin-top: 20px;
            padding: 10px;
            background: rgba(255,215,0,0.05);
            border: 1px solid #ffd700;
            font-size: 12px;
            color: rgba(255,215,0,0.7);
        }
        @keyframes pulse {
            0%, 100% { opacity: 1; }
            50% { opacity: 0.6; }
        }
        .security-status.updating {
            animation: pulse 1s ease-in-out infinite;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1 id="dashboard-title">SECURITY DASHBOARD</h1>
            <p class="subtitle">BANK VAULT MONITORING</p>
        </div>
        
        <a href="/security" class="back-link">← BACK TO SECURITY CENTER</a>
        
        <div class="dashboard" id="dashboard">
            <!-- Security cards will be populated by JavaScript -->
        </div>
        
        <div class="update-info">
            Last update: <span id="last-update">--</span> | Auto-refresh: <span id="refresh-status">ON</span>
        </div>
    </div>
    
    <script>
        const sensorType = window.location.pathname.split('/').pop();
        let updateInterval;
        
        // Update dashboard title based on sensor type
        const titles = {
            'door': 'DOOR SENSOR SYSTEM',
            'touch': 'DOOR SENSOR SYSTEM',
            'vibration': 'INTRUSION DETECTION SYSTEM'
        };
        if (titles[sensorType]) {
            document.getElementById('dashboard-title').textContent = titles[sensorType];
        }
        
        async function fetchSensorData() {
            try {
                // Map 'touch' to 'door' for API call
                const apiPath = sensorType === 'touch' ? 'door' : sensorType;
                const response = await fetch('/security/api/' + apiPath);
                const data = await response.json();
                updateDashboard(data);
                document.getElementById('last-update').textContent = new Date().toLocaleTimeString();
            } catch (error) {
                console.error('Error fetching sensor data:', error);
                showError('Failed to read sensor. Check connections.');
            }
        }
        
        function updateDashboard(data) {
            const dashboard = document.getElementById('dashboard');
            dashboard.innerHTML = '';
            
            if (data.error) {
                dashboard.innerHTML = `
                    <div class="security-card" style="grid-column: 1 / -1;">
                        <div class="security-status" style="color: #ff0000;">ERROR</div>
                        <p style="margin-top: 15px; color: rgba(255,255,255,0.7);">${data.error}</p>
                        <p style="margin-top: 10px; font-size: 12px; color: rgba(255,255,255,0.5);">
                            Check sensor connections and pin configuration.
                        </p>
                    </div>
                `;
                return;
            }
            
            // Create cards based on sensor type
            if (sensorType === 'door' || sensorType === 'touch') {
                const cardClass = data.doorOpen ? 'security-card touch authorized' : 'security-card touch';
                dashboard.innerHTML = `
                    <div class="${cardClass}">
                        <div class="security-icon">${data.doorOpen ? '🚪' : '🔒'}</div>
                        <div class="security-label">Vault Door</div>
                        <div class="security-status">${data.doorOpen ? 'DOOR OPEN' : 'DOOR CLOSED'}</div>
                        <div class="security-value">Sensor Value: ${data.rawValue !== undefined ? data.rawValue : '--'}</div>
                        <div class="security-description">
                            <strong>Status:</strong> ${data.doorOpen ? 'Door is open' : 'Door is closed'}<br>
                            <strong>Security:</strong> ${data.doorOpen ? '⚠️ Vault accessible' : '✅ Vault secured'}<br><br>
                            <em>Touch switch activated = Door open. Deactivated = Door closed.</em>
                        </div>
                    </div>
                `;
            } else if (sensorType === 'vibration') {
                const cardClass = data.alert ? 'security-card vibration alert' : 'security-card vibration';
                dashboard.innerHTML = `
                    <div class="${cardClass}">
                        <div class="security-icon">${data.alert ? '🚨' : data.detected ? '⚠️' : '🔒'}</div>
                        <div class="security-label">Intrusion Detection</div>
                        <div class="security-status">${data.alert ? 'BREACH ALERT' : data.detected ? 'VIBRATION DETECTED' : 'SECURE'}</div>
                        <div class="security-value">Vibration Level: ${data.level !== undefined ? data.level + '%' : '--'}</div>
                        <div class="security-description">
                            <strong>Status:</strong> ${data.detected ? 'Vibration detected' : 'No vibration'}<br>
                            <strong>Alert Level:</strong> ${data.alert ? 'BREAK-IN ATTEMPT' : data.detected ? 'Monitoring' : 'All clear'}<br><br>
                            <em>Breach alert triggers after 3+ vibrations within 2 seconds.</em>
                        </div>
                    </div>
                `;
            }
        }
        
        function showError(message) {
            const dashboard = document.getElementById('dashboard');
            dashboard.innerHTML = `
                <div class="security-card" style="grid-column: 1 / -1;">
                    <div class="security-status" style="color: #ff0000;">ERROR</div>
                    <p style="margin-top: 15px; color: rgba(255,255,255,0.7);">${message}</p>
                </div>
            `;
        }
        
        // Start auto-refresh (vibration needs faster polling so short pulses show up)
        fetchSensorData();
        const refreshMs = (sensorType === 'vibration') ? 400 : 2000;
        updateInterval = setInterval(fetchSensorData, refreshMs);
        
        // Cleanup on page unload
        window.addEventListener('beforeunload', () => {
            if (updateInterval) clearInterval(updateInterval);
        });
    </script>
</body>
</html>
)rawliteral";

#endif
