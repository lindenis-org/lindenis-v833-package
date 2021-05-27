/*
 * Copyright 2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "BlueZ/BlueZBluetoothDeviceManager.h"

namespace alexaClientSDK {
namespace bluetoothImplementations {
namespace blueZ {

using namespace avsCommon::sdkInterfaces::bluetooth;
using namespace avsCommon::sdkInterfaces::bluetooth::services;
using namespace avsCommon::utils;

std::shared_ptr<BluetoothHostControllerInterface> BlueZBluetoothDeviceManager::getHostController() {
    return m_deviceManager->getHostController();
}

std::list<std::shared_ptr<BluetoothDeviceInterface>> BlueZBluetoothDeviceManager::getDiscoveredDevices() {
    return m_deviceManager->getDiscoveredDevices();
}

std::unique_ptr<BlueZBluetoothDeviceManager> BlueZBluetoothDeviceManager::create(
    std::shared_ptr<avsCommon::utils::bluetooth::BluetoothEventBus> eventBus) {
    auto deviceManager = BlueZDeviceManager::create(eventBus);
    if (!deviceManager) {
        return nullptr;
    }
    return std::unique_ptr<BlueZBluetoothDeviceManager>(new BlueZBluetoothDeviceManager(deviceManager));
}

BlueZBluetoothDeviceManager::BlueZBluetoothDeviceManager(std::shared_ptr<BlueZDeviceManager> deviceManager) :
        m_deviceManager{deviceManager} {
}

}  // namespace blueZ
}  // namespace bluetoothImplementations
}  // namespace alexaClientSDK
