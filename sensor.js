let csv = "";
let aX = 0, aY = 0, aZ = 0;
let alpha = 0, beta = 0, gamma = 0;    
let destination = {"latitude": 0, "longitude": 0};
let latitude;
let longitude;
let distance, bearing;
const pole_radius = 6356752.314245;
const equator_radius = 6378137.0;
const e2 = (Math.pow(equator_radius, 2) - Math.pow(pole_radius, 2))/Math.pow(equator_radius, 2);
let gps_data = document.querySelector('#gps_data')
document.addEventListener("DOMContentLoaded", function() {
    // オプション・パラメータをセット
    var position_options = {
        // 高精度を要求する
        enableHighAccuracy: true,
        // 最大待ち時間（ミリ秒）
        timeout: 60000,
        // キャッシュ有効期間（ミリ秒）
        maximumAge: 0
    };
    // 現在位置情報を取得
    navigator.geolocation.watchPosition(monitor, null, position_options);

    setInterval(() => {
        window.addEventListener("devicemotion", (dat) => {
            aX = dat.accelerationIncludingGravity.x;    // x軸の重力加速度（Android と iOSでは正負が逆）
            aY = dat.accelerationIncludingGravity.y;    // y軸の重力加速度（Android と iOSでは正負が逆）
            aZ = dat.accelerationIncludingGravity.z;    // z軸の重力加速度（Android と iOSでは正負が逆）
        });
        let date = new Date();
        let date_element = document.querySelector("#date");
        date_element.textContent = date.toString();
        let aX_element = document.querySelector("#aX");
        aX_element.textContent = aX;
        let aY_element = document.querySelector("#aX");
        aY_element.textContent = aY;
        let aZ_element = document.querySelector("#aX");
        aZ_element.textContent = aZ;
        csv += date.toString() + "," + aX + "," + aY + "," + aZ + "\n"; 
    }, 50)
    


    //地磁気（方角）
    setInterval(() => {
        window.addEventListener("deviceorientationabsolute", (dat) => {
            alpha = dat.alpha;
            beta = dat.beta;
            gamma = dat.gamma;
            alpha -= gamma;
            alpha *= -1;
            alpha = correction(alpha);
        })
        let date = new Date();
        let date_element = document.querySelector("#date");
        date_element.textContent = date.toString();
        let alpha_element = document.querySelector("#alpha");
        alpha_element.textContent = alpha;
        let beta_element = document.querySelector("#beta");
        beta_element.textContent = beta;
        let gamma_element = document.querySelector("#gamma");
        gamma_element.textContent = gamma;
        csv += date.toString(); + "," + alpha + "," + beta + "," + gamma + "\n"; 
        }, false);
    }, 50)
    

// 位置情報取得完了時の処理
function monitor(event) {
    // 緯度
    latitude = event.coords.latitude;
    // 経度
    longitude = event.coords.longitude;
    // タイムスタンプ
    let date = new Date();

    let latitude_difference = destination.latitude - latitude;
    let longitude_difference = destination.longitude - longitude;
    let latitude_average = (latitude + destination.latitude)/2;

    bearing = Math.atan2(latitude_difference, longitude_difference) * 180 / Math.PI;
    let w = Math.sqrt(1- e2 * Math.pow(Math.sin(latitude_average), 2));
    let m = equator_radius * (1 - e2) / Math.pow(w, 3);
    let n = equator_radius / w;
    distance = Math.sqrt(Math.pow(m * latitude_difference, 2) + Math.pow(n * longitude_difference * Math.cos(latitude_average), 2));

    let date_element = document.querySelector("#date");
    date_element.textContent = date.toString();
    let latitude_element = document.querySelector("#latitude");
    latitude_element.textContent = latitude;
    let longitde_element = document.querySelector("#longitude");
    longitde_element.textContent = longitude;
    let bearing_element = document.querySelector("#bearing");
    bearing_element.textContent = bearing;
    let distance_element = document.querySelector("#distance");
    distance_element.textContent = distance;

    
    csv += date.toString() + "," + latitude + "," + longitude + "\n";
}

function correction(alpha) {
    while (alpha >= 360) {
        alpha -= 360;
    }

    while (alpha < 0) {
        alpha += 360;
    }
    return alpha;
}


function download_csv() {
    console.log(i)
    var bom = new Uint8Array([0xEF, 0xBB, 0xBF]);
    const blob = new Blob([bom, csv], {type: "text/csv"});
    const a = document.createElement("a");
    const url = URL.createObjectURL(blob);
    a.href = url;
    i += 1;

    a.download = "gps" + i + ".csv";
    a.click();
    URL.revokeObjectURL(url);
}

function set_destination() {
    setTimeout(() => {
        destination.latitude = latitude;
        destination.longitude = longitude;
    }, 1000);
}

//5分おきに勝手にcsvデータダウンロード
setInterval(() => {
    download_csv();
}, 300000)

//ボタンが押されたときにcsvデータダウンロード
document.getElementById("download").addEventListener("click", function() {
    download_csv();
})

document.getElementById("destination").addEventListener("click", function() {
    set_destination();
})
