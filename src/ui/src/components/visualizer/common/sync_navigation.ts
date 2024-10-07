/**
 * @license
 * Copyright 2024 The Model Explorer Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ==============================================================================
 */

import {TaskData, TaskType} from './task';

/** The data for navigation syncing. */
export interface SyncNavigationData extends TaskData {
  type: TaskType.SYNC_NAVIGATION;

  mapping: SyncNavigationMapping;
}

/**
 * The mapping for navigation syncing, from node id from one side to node id
 * from another side.
 */
export type SyncNavigationMapping = Record<string, string>;

/** The mode of navigation syncing. */
export enum SyncNavigationMode {
  DISABLED = 'disabled',
  MATCH_NODE_ID = 'match_node_id',
  VISUALIZER_CONFIG = 'visualizer_config',
  UPLOAD_MAPPING_FROM_COMPUTER = 'from_computer',
  LOAD_MAPPING_FROM_CNS = 'from_cns',
}

/** The labels for sync navigation modes. */
export const SYNC_NAVIGATION_MODE_LABELS = {
  [SyncNavigationMode.DISABLED]: 'Disabled',
  [SyncNavigationMode.MATCH_NODE_ID]: 'Match node id',
  [SyncNavigationMode.UPLOAD_MAPPING_FROM_COMPUTER]:
    'Upload mapping from computer',
  [SyncNavigationMode.LOAD_MAPPING_FROM_CNS]: 'Load mapping from CNS',
  [SyncNavigationMode.VISUALIZER_CONFIG]: 'From Visualizer Config',
};

/** Information about the source of navigation. */
export interface NavigationSourceInfo {
  paneIndex: number;
  nodeId: string;
}
