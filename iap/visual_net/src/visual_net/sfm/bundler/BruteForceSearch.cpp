/* * IAP - Interactive Perception System - Segment visually observable environment
 * into rigid bodies and estimate type and properties of joints between them by
 * means of interaction.
 * Copyright (C) 2012 Technische Universitaet Berlin - RBO
 * <robotics@robotics.tu-berlin.de>
 * 
 * This file is part of IAP.
 * 
 * IAP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * IAP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with IAP.  If not, see <http://www.gnu.org/licenses/>.
 */
/* 
 *  Copyright (c) 2008-2010  Noah Snavely (snavely (at) cs.cornell.edu)
 *    and the University of Washington
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

/* BruteForceSearch.cpp */
/* Brute force nearest-neighbor search data structure */

#include "BruteForceSearch.h"

#include "../libs/imagelib/qsort.h"
#include "../libs/matrix/vector.h"

BruteForceSearch::BruteForceSearch(int n, v3_t *pts)
{
    m_num_points = n;
    m_points = new v3_t[n];
    
    for (int i = 0; i < n; i++)
	m_points[i] = pts[i];
}

void BruteForceSearch::GetClosestPoints(v3_t query, int num_points, 
					int *idxs, double *dists)
{
    double *dists_all = new double[m_num_points];
    
    for (int i = 0; i < m_num_points; i++) {
	dists_all[i] = v3_magsq(v3_sub(query, m_points[i]));
    }
    
    int *perm = new int[m_num_points];
    qsort_ascending();
    qsort_perm(m_num_points, dists_all, perm);

    for (int i = 0; i < num_points; i++) {
	idxs[i] = perm[i];
	dists[i] = dists_all[i];
    }

    delete [] dists_all;
    delete [] perm;
}
